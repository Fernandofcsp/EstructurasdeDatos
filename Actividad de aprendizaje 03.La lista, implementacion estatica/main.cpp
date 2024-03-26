#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include "Lista.h"
#include "Cancion.h"
using namespace std;
int main()
{
Lista myLista;
Cancion myMusica;
char opc;
system("CLS");
myLista.Inicializa();
int x = 1;
int valor = 0;
int pos, ran;
string canc, aut;
do
{
system("CLS");
cout<<"\t\t\tLista de canciones:"<<endl<<endl;
myLista.Imprimir();
cout<<"\nSelecciona una opcion: "<<endl;
cout<<"1) Agregar cancion"<<endl;
cout<<"2) Eliminar cancion"<<endl;
cout<<"3) Salir del programa"<<endl;
cin>> opc;
switch(opc)
{
case '1':
system("CLS");
cout<<"Opcion seleccionada: Agregar cancion"<<endl<<endl;
cout<<"Ingrese el nombre de la cancion: ";
fflush(stdin);
getline(cin,canc);
myMusica.sCancion(canc);
cout<<"Ingrese el nombre del autor: ";
fflush(stdin);
getline(cin,aut);
myMusica.sAutor(aut);
cout<<"Ingrese el ranking de la cancion: ";
fflush(stdin);
cin>>ran;
myMusica.sRanking(ran);
myLista.Inserta(myLista.ultimaPosicion(), myMusica);
break;
case '2':
cout<<"Opcion seleccionada: Eliminar elemento"<<endl<<endl;
cout<<"Ingrese la posicion del elemento que desea eliminar: ";
cin>>pos;
if(myLista.Validar(pos) == 1)
{
myLista.eliminarPos(pos);
cout<<"Elemento eliminado de forma correcta, regresando al menu principal..."
;
Sleep(3000);
}
else
{
cout<<"\nLa posicion ingresada es incorrecta! Regresando al menu principal...";
Sleep(3000);
}
break;
}
}while(x != 0);
}
