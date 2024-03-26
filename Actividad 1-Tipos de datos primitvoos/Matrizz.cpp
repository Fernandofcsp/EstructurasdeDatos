#include "Matrizz.h"
#include "time.h"
#include <iomanip>
#include <stdlib.h>
#include <iostream>

using namespace std;

void Matriz::Tamano(int tam){//tamaño de la matriz

	i=tam;
	j=tam;

}

void Matriz::Llenar(){//Llenado de la matriz
	srand(time(NULL));
	for (int f=0;f<i;f++){
		for (int c=0;c<j;c++){
			matriz1[f][c]=((rand()%100)*0.01)-99+(rand()%200);
			matriz2[f][c]=((rand()%100)*0.01)-99+(rand()%200);
			suma[f][c]=matriz1[f][c]+matriz2[f][c];
			multiplicar[f][c]=matriz1[f][c]*matriz2[f][c];

		}
	}
}
void Matriz::Mostrar(){

	cout<<"Matriz 1\n\n"<<endl<<endl;
	for (int f=0;f<i;f++){
		for (int c=0;c<j;c++)
			cout<<setw(10)<<matriz1[f][c]<<setw(10);
			cout<<"\n\n";
	}

	cout<<"\nMatriz 2\n\n"<<endl<<endl;
	for (int f=0;f<i;f++){
		for (int c=0;c<j;c++)
			cout<<setw(10)<<matriz2[f][c]<<setw(10);
			cout<<"\n\n";

	}
	cout<<"\nSuma de las matrices\n\n"<<endl<<endl;
	for (int f=0;f<i;f++){
		for (int c=0;c<j;c++)
			cout<<setw(10)<<suma[f][c]<<setw(10);
			cout<<"\n\n";

	}
	cout<<"\nMultiplicacion de las matrices 3\n\n"<<endl<<endl;
	for (int f=0;f<i;f++){
		for (int c=0;c<j;c++)
			cout<<setw(10)<<multiplicar[f][c]<<setw(14);
			cout<<"\n\n";

	}
}
