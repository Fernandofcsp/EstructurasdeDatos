#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Proyecto.h"

#define MAX_REGISTROS 10
#define INDICE_PRIMARIO "indice_primario.txt"
#define INDICE_SECUNDARIO "indice_secundario.txt"

#define SEPARADOR_CAMPO "♣"
#define SEPARADOR_REGISTRO '♣'

using namespace std;

int menu();
void trazarArchivo(string, unsigned int);

void capturaDatos();
void consultaFolio(string);
void consultaArea(string);

inline void pausa()
{
    string e;
    cout << endl << "Presione enter para continuar..." << endl;
    cin.ignore();
    getline(cin, e, '\n');
}

int main (){

    int opcion;

    do{

        opcion = menu();

        switch (opcion){
            case 1:
                capturaDatos();
                pausa();
                break;

            case 2:
                consultaFolio("proyecto.txt");
                break;

            case 3:
                consultaArea("proyecto.txt");
                break;

            case 4:

                break;

            default:
                cout << "404 NOT FOUND" << endl << endl;
                break;
        }

    }while(opcion != 4);


    return  0;
}

int menu(){

    int opcion;

    cout << "Menu Principal: "<<endl;
    cout << "1. Insertar Proyecto"<<endl;
    cout << "2. Mostrar Proyecto por Folio "<<endl;
    cout << "3. Mostrar Proyecto por Areas "<<endl;
    cout << "4. Salir" <<endl;
    cout << "Ingresa una opcion: ";
    cin >> opcion;
    cout << endl << endl;

    return opcion;

}


void capturaDatos() {

    trazarArchivo("Proyecto.txt",MAX_REGISTROS);

    Proyecto miProyecto;

    int opc;

    string folio;
    string nombre;
    string area;
    string especialidad;
    string monto;
    string responsable;

    ofstream archivoProyecto;


    archivoProyecto.open("proyecto.txt", ios::in | ios::out | ios::ate | ios::binary);

    cout << "Nombre: ";
    cin  >> nombre;
    miProyecto.setNombre(nombre);


    cout << "   1  Area I: FISICO MATEMATICAS Y CIENCIAS DE LA TIERRA."<<endl;
    cout << "   2  AREA II: BIOLOGIA Y QUIMICA."<<endl;
    cout << "   3  AREA III: CIENCIAS MEDICAS Y DE LA SALUD."<<endl;
    cout << "   4  AREA IV: HUMANIDADES Y CIENCIAS DE LA CONDUCTA."<<endl;
    cout << "   5  AREA V: CIENCIAS SOCIALES."<<endl;
    cout << "   6  AREA VI: BIOTECNOLOGIA Y CIENCIAS AGROPECUARIAS."<<endl;
    cout << "   7  AREA VII: INGENIERIAS."<<endl;

    cout << "Ingresa el numero de area: ";
    cin  >> opc;

    if(opc == 1){
        miProyecto.setArea("Area I: FISICO MATEMATICAS Y CIENCIAS DE LA TIERRA.");
    }
    else if (opc == 2){
        miProyecto.setArea("AREA II: BIOLOGIA Y QUIMICA");
    } else if (opc == 3){
        miProyecto.setArea("AREA III: CIENCIAS MEDICAS Y DE LA SALUD");
    } else if (opc == 4){
        miProyecto.setArea("AREA IV: HUMANIDADES Y CIENCIAS DE LA CONDUCTA");
    } else if (opc == 5){
        miProyecto.setArea("AREA V: CIENCIAS SOCIALES");
    } else if (opc == 6){
        miProyecto.setArea("AREA VI: BIOTECNOLOGIA Y CIENCIAS AGROPECUARIAS.");
    } else if(opc == 7){
        miProyecto.setArea("AREA VII: INGENIERIAS");
    }

    cout <<"Especialidad: ";
    cin  >> especialidad;
    miProyecto.setEspecialidad(especialidad);

    cout << "Monto: ";
    cin  >> monto;
    miProyecto.setMonto(monto);

    cout <<"Responsable: ";
    cin  >> responsable;
    miProyecto.setResponsable(responsable);
    cout << "Folio genenerado con exito"<<endl;

    miProyecto.folio(nombre);

    archivoProyecto.write(reinterpret_cast<const char*>(&miProyecto), sizeof(Proyecto));
    archivoProyecto.close();
}

void trazarArchivo(string rutaArchivo , unsigned int cantidadRegistros) {

    ifstream archivoViejo(rutaArchivo);
    ofstream archivoNuevo;
    Proyecto proyectoVacio;

    if(!archivoViejo.good()){
        archivoViejo.close();
        archivoNuevo.open(rutaArchivo, ios::binary);

        for(unsigned int i=0; i < cantidadRegistros; i++)
            archivoNuevo.write(reinterpret_cast<const char *>(&proyectoVacio), sizeof(Proyecto));
        archivoNuevo.close();
    } else
        archivoViejo.close();
}


void consultaFolio(string) {


    return;

}



void consultaArea(string) {

    return;
}

