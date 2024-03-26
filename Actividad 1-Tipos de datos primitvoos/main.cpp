#include <iostream>
#include <stdlib.h>
#include "Matrizz.h"
#include "Tabla.h"

using namespace std;

int main(){

	char opcion;
	do{
        cout<<"\n                    MENU\n";
        cout<<"\na)Tamano y rango de tipos de dato primitivos";
        cout<<"\nb)Ejemplo de uso de dato de tipo esctructurado";
        cout<<"\nc)Salir\n";
        cin>>opcion;

	switch(opcion){
		case 'a':
			Tabla Ob2;
			Ob2.MostrarTamano();
		break;
		case 'b':
			Matriz Ob1;
			int tam;
			cout<<"\nDe que tama\xA4o quieres tu matriz? Min 3 - Max 10\n";
			cin>>tam;

			while (tam<3 || tam>10){
				cout<<"\nIngresa un numero MAYOR a 3 y MENOR a 10\n";
				cin>>tam;
			}
			Ob1.Tamano(tam);
			Ob1.Llenar();
			Ob1.Mostrar();

			break;
		case 'c':cout<<"\n\nGracias por usar el programa\n\n";
			break;
		default: cout<<"\nOpcion invalida\n\n";
			break;
	}
	system ("pause");
	system("cls");


	}while(opcion!='c');


	return 0;
}
