#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "RandomNumbers.h"
#include "Methods.h"
using namespace std;

int main()
{
    float first, last, result;
    Methods myMethods;
    Methods myMethods2;
    RandomNumbers myRandom;

    long int data;

    srand(time(NULL));

    for( int i(0) ; i < 100000 ; i++ ){
        data = (rand() % 1000) * (rand() % 1000);
        myRandom.setRandom(data);
        myMethods.setNumber(myRandom);
    }

    myMethods2 = myMethods;

    cout << "Metodo[Burbuja] -Tiempo: ";
    first = clock();
    myMethods.bubbleSort();
    last = clock();
    result = (last-first) / 1000 ;
    cout << result << " Segundos" << endl << endl;

    myMethods = myMethods2;

    cout << "Metodo[Shell] -Tiempo: ";
    first = clock();
    myMethods.shellSort();
    last = clock();
    result = (last-first) / 1000 ;
    cout << result << " Segundos" << endl << endl;

    myMethods = myMethods2;

    cout << "Metodo[Insercion] -Tiempo: ";
    first = clock();
    myMethods.insertSort();
    last = clock();
    result = (last-first) / 1000 ;
    cout << result << " Segundos" << endl << endl;

    myMethods = myMethods2;

    cout << "Metodo[Seleccion] -Tiempo: ";
    first = clock();
    myMethods.selectionSort();
    last = clock();
    result = (last-first) / 1000 ;
    cout << result << " Segundos" << endl << endl;

    myMethods = myMethods2;

    cout << "Metodo[Mezcla] -Tiempo: ";
    first = clock();
    myMethods.mergeSort();
    last = clock();
    result = (last-first) / 1000 ;
    cout << result << " Segundos" << endl << endl;

    myMethods = myMethods2;

    cout << "Metodo[QuickSort] -Tiempo: ";
    first = clock();
    myMethods.quickSort();
    last = clock();
    result = (last-first) / 1000 ;
    cout << result << " Segundos" << endl << endl;

    return 0;
}
