#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int counter=0;
const int S=500;

struct Inventario
{
    string eliminar;
    string name;
    string code;
    float weight;
    float pricemay;
    float pricemen;
    int existencia;
    int opt;

}inventario[S];
struct Fecha
{
        int day;
        int month;
        int year;
}fecha[S];
void agregar();
void eliminar();
void mostrar();
void salir();


enum OPTIONS
{
    OPT_ADD = 1,
    OPT_DELETE,
    OPT_SHOW,
    OPT_EXIT
};



int main()
{

int opt;
    do
    {
    system("cls");
    cout<<"\n\n\t\t\t* * * * * MENU DE OPCIONES * * * * *"<<endl
        <<OPT_ADD<<") Agregar producto" <<endl
        <<OPT_DELETE<<") Borrar/Restar cantidad de producto" <<endl
        <<OPT_SHOW<<") Mostrar productos" <<endl
        <<OPT_EXIT<<") Salir del programa" <<endl
        <<"Selecciona una opcion: ";
        cin>>opt;
        cin.ignore();
        system("cls");
        switch (opt)
        {
case OPT_ADD: agregar();
    break;
case OPT_DELETE: eliminar();
    break;
case OPT_SHOW: mostrar();
    break;
case OPT_EXIT: salir();
    break;
        }
    }
    while(opt != OPT_EXIT);
}

void agregar()
{
int opt;

if (counter < S)
{

                cout<<"Ingresa la siguiente informacion"<<endl
                <<"Nombre: ";
                getline(cin, inventario[counter].name);
                cout<<"Codigo de barras de 13 digitos: "<<endl;
                getline(cin, inventario[counter].code);
                cout<<"Peso:"<<endl;
                cin>>inventario[counter].weight;
                cout<<"Precio al mayoreo:  "<<endl;
                cin>>inventario[counter].pricemay;
                cout<<"Precio al menudeo:  "<<endl;
                cin>>inventario[counter].pricemen;
                cout<<"Cantidad en existencia:  "<<endl;
                cin>>inventario[counter].existencia;
                cout<<"Proporciona la fecha dd/mm/aa presiona intro cada dos digitos"<<endl;
                cin>>fecha[counter].day>>fecha[counter].month>>fecha[counter].year;

       system("cls");
        counter++;
}
            else
            cout<<"No hay espacios disponibles"<<endl;
}

void eliminar()
{
    string borrar;
    cout<<"Proporcione el C. de Barras para eliminar o restar una cantidad de un producto"<<endl;
    getline(cin, borrar);
    for (int a(0);a<counter;a++)
    {
        if (borrar==inventario[a].code)
{
    inventario[a].existencia=(inventario[a].existencia)-1;
}

    }
    for (int a(0);a<counter;a++)
    {
    if(inventario[a].existencia<0)
        {
          inventario[a].existencia=(inventario[a].existencia)+1;
            cout<<"No se pueden restar mas productos porque estos ya son 0"<<endl;
            system ("pause");
        }
    }
}

void mostrar()
{


    for(int i(0);i<counter;i++)
            {
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Nombre: "<<inventario[i].name<<endl;
    cout<<"Codigo de barras: "<<inventario[i].code<<endl;
    cout<<"Peso: "<<inventario[i].weight<<endl;
    cout<<"Precio al mayoreo: "<<inventario[i].pricemay<<endl;
    cout<<"Precio al menudeo: "<<inventario[i].pricemen<<endl;
    cout<<"Existencia actual: "<<inventario[i].existencia<<endl;
    cout<<"Fecha: "<<fecha[i].day<<"-"<<fecha[i].month<<"-"<<fecha[i].year<<endl;
            }
    system("pause");
    system("cls");

}

void salir()
{
cout<<"El programa ha finalizado, presione cualquier tecla para salir."<<endl;
}
