#include <iostream>
#include <fstream> ///FileStream ~ Flujo de archivos
#include <string>
#include <cstring>
#define DELIMITADOR_CAMPOS ',' ///definicion del delimitador de campos
#define SEPARADOR_REGISTROS '\n' ///definicion del sperador de registros
using namespace std;

int main () {
int opc; /// inicializacion de la variable para las opciones del menu
    do
    {
cout<<"Menu de opciones\n1.-Ejecutar intercalacion\n2.-Salir"<<endl; ///Menu de opciones
cin>>opc;
if (opc==1)
{
    ///Archivos a utilizar fstream del flujo de archivos
    fstream mezcla;
    fstream inventario1("Inventario1.txt");
    fstream inventario2("Inventario2.txt");
    bool band = true; ///Bandera fin de archivo

    ///Abrir archivo resultante mezcla.txt con la intercalacion ordenada
    mezcla.open("mezcla.txt",ios::out);
    mezcla.seekg(ios::beg); ///buscar desde el principio del stream getpointer seekg retorna la posicion
    string registro1, registro2;///Variables de lectura
    char comparacion1[20], comparacion2[20];///Variables de comparacion

    if( !inventario1 or !inventario2 ) {///Revisar que ambos archivos existan
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
        }
    if ( !inventario1.eof() ) { ///Revisar que el primer archivo tenga elementos por leer
        getline(inventario1,registro1,SEPARADOR_REGISTROS); ///Leer registro completo
        registro1 += SEPARADOR_REGISTROS;
        }

    if ( !inventario2.eof() ) { ///Revisar que el segundo archivo tenga elementos por leer
        ///Leer registro completo completa
        getline(inventario2,registro2,SEPARADOR_REGISTROS);
        registro2 += SEPARADOR_REGISTROS;
        }

    for( int i = 0 ; i < 20 ; i++) { ///Hacer la primera cadena comparable
        if( registro1[i] == DELIMITADOR_CAMPOS ) {
            break;
            }
        comparacion1[i] = registro1[i];
        }

    for( int i = 0 ; i < 20 ; i++) { ///Hacer la primera cadena comparable
        if( registro2[i] == DELIMITADOR_CAMPOS ) {
            break;
            }
        comparacion2[i] = registro2[i];
        }
    ///Mientras que uno de los archivos tenga registros para leer
    while ( !inventario1.eof() or !inventario2.eof() ){
            ///Comparar un registro respecto al otro
            if ( strcmp(comparacion1,comparacion2) < 0 ) {
                ///Revisar que sea leible el primer archivo
                if ( !inventario1.eof() ) {
                    ///Escribir el registro al archivo resultante y recorrer la comparacion
                    mezcla << registro1;
                    getline(inventario1,registro1,SEPARADOR_REGISTROS);
                    registro1 += SEPARADOR_REGISTROS;
                    for( int i = 0 ; i < 20 ; i++) {
                        if( registro1[i] == DELIMITADOR_CAMPOS ) {
                            break;
                            }
                        comparacion1[i] = registro1[i];
                        }
                    }
                ///Si el archivo no puede serguir siendo leido
                else {
                    ///Al terminar con el primer archivo, es necesario solo trabajar con el segundo
                    /// entonces, para no brincar ningun registro, se escribe el que quedo siendo el mayor al final
                    if( band ){
                        mezcla << registro2;
                        band = false;
                    }
                    ///Escribir unicamente lo que queda en el segundo archivo
                    getline(inventario2,registro2,SEPARADOR_REGISTROS);
                    registro2 += DELIMITADOR_CAMPOS;
                    mezcla << registro2;
                    }
                }
            ///Trabaja de forma espejo en respecto al archivo uno
            else {
                if ( !inventario2.eof() ) {
                    mezcla << registro2;
                    getline(inventario2,registro2,SEPARADOR_REGISTROS);
                    registro2 += SEPARADOR_REGISTROS;
                    for( int i = 0 ; i < 20 ; i++) {
                        if( registro2[i] == SEPARADOR_REGISTROS ) {
                            break;
                            }
                        comparacion2[i] = registro2[i];
                        }
                    }
                else {
                    if( band ){
                        mezcla << registro1;
                        band = false;
                    }
                    getline(inventario1,registro1,SEPARADOR_REGISTROS);
                    registro1 += SEPARADOR_REGISTROS;
                    mezcla << registro1;
                    }
                }
        }
        cout<<"Intercalacion realizada correctamente\nEl resultado es:"<<endl;
            FILE *archivo = fopen("mezcla.txt", "r"); ///abre el archivo en modo lectura
            int c;
            while((c=fgetc(archivo))!=EOF) ///lee e imprime desde el inicio hasta el final del archivo
            {
            putchar(c);
            }
            system("pause"); ///pone en espera el programa
            system("cls"); ///limpia la pantalla de consola
}
    else if (opc!=2)
    {
          cout<<"Opcion inexistente"<<endl;
          system("pause"); ///pone en espera el programa
          system("cls"); ///limpia la pantalla de consola
    }
    }while (opc!=2);
        cout<<"Fin de programa, presione cualquier tecla para cerrar la ventana"<<endl; ///Fin del programa
        return 0;

    } ///fin del inicio principal
