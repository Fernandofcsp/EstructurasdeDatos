#ifndef PILA_H
#define PILA_H
#include <iostream>
#define MAX 1000



class Pila
{
private:
char valores[MAX];
int ultimo;
public:
void Inicializa();
int Vacia();
int Llena();
void Push(char);
void Pop();
char Top();
int getLastPos();
};

#endif // PILA_H
