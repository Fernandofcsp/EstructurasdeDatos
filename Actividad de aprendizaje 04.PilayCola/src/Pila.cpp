#include "Pila.h"
void Pila::Inicializa()
{
ultimo = -1;
}
int Pila::Vacia()
{
if(ultimo == -1)
return 1;
else
return 0;
}
int Pila::Llena()
{
if(ultimo == MAX - 1)
return 1;
else
return 0;
}
void Pila::Push(char a)
{
ultimo = ultimo + 1;
valores[ultimo] = a;
}
void Pila::Pop()
{
ultimo = ultimo - 1;
}
char Pila::Top()
{
return valores[ultimo];
}
int Pila::getLastPos()
{
return ultimo;
}
