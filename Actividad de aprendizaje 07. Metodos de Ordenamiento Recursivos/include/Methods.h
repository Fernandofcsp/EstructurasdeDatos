#ifndef METHODS_H
#define METHODS_H
#include "RandomNumbers.h"

 class Methods {
private:
	RandomNumbers AllMethods[100000];
	RandomNumbers temp[100000];
	void copyAll(const Methods&);
	int last;
	void mergeSort(const int&,const int&);
	void quickSort(const int&,const int&);
public:
	Methods();
	bool isFull();
	void setNumber(const RandomNumbers&);
    long int getNumber(const int&);
    void swapAllMethods(RandomNumbers&,RandomNumbers&);

    int getLastPos();
	void bubbleSort();
	void shellSort();
	void insertSort();
	void selectionSort();
	void mergeSort();
	void quickSort();
	Methods& operator = (const Methods&);
};
#endif // METHODS_H
