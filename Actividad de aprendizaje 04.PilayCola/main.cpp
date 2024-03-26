#include <iostream>
#include <windows.h>
#include <cstdio>
#include "Pila.h"
using namespace std;
int main()
{
int res = -1;
int x = 0;
int longitud = 0;
char expresion[1024];
char result[1024];
Pila objectPila;
objectPila.Inicializa();
do
{
system("cls");
cout<<"Ingrese la operacion en notacion infija: ";
cin.ignore();
gets(expresion);
longitud = strlen(expresion);
for(int y = 0; y <= longitud; y++)
{
switch(expresion[y])
{
case '(':
objectPila.Push(expresion[y]);
break;
case ')':
for(int z = objectPila.getLastPos(); z != -1; z--)
{
if(objectPila.Top() == '(')
{
objectPila.Pop();
z = -1;
break;
}
else
{
res++;
result[res] = objectPila.Top();
objectPila.Pop();
}
}
break;
case '+':
if(objectPila.Vacia() == 1)
{
objectPila.Push(expresion[y]);
break;
}
if(objectPila.Top() == '(')
{
objectPila.Push(expresion[y]);
break;
}
for(int z = objectPila.getLastPos(); z != -1; z--)
{
if(objectPila.Top() == '(')
{
objectPila.Pop();
z = -1;
break;
}
else
{
res++;
result[res] = objectPila.Top();
objectPila.Pop();
}
}
case '-':
if(objectPila.Vacia() == 1)
{
objectPila.Push(expresion[y]);
break;
}
if(objectPila.Top() == '(')
{
objectPila.Push(expresion[y]);
break;
}
for(int z = objectPila.getLastPos(); z != -1; z--)
{
if(objectPila.Top() == '(')
{
objectPila.Pop();
z = -1;
break;
}
else
{
res++;
result[res] = objectPila.Top();
objectPila.Pop();
}
}
case '*':
if(objectPila.Vacia() == 1)
{
objectPila.Push(expresion[y]);
break;
}
if(objectPila.Top() == '(')
{
objectPila.Push(expresion[y]);
break;
}
if(objectPila.Top() == '^' or objectPila.Top() == '*' or objectPila.Top() == '/')
{
res++;
result[res] = objectPila.Top();
objectPila.Pop();
objectPila.Push(expresion[y]);
}
else
{
objectPila.Push(expresion[y]);
}
break;
case '/':
if(objectPila.Vacia() == 1)
{
objectPila.Push(expresion[y]);
break;
}
if(objectPila.Top() == '(')
{
objectPila.Push(expresion[y]);
break;
}
if(objectPila.Top() == '^' or objectPila.Top() == '*' or objectPila.Top() == '/')
{
res++;
result[res] = objectPila.Top();
objectPila.Pop();
objectPila.Push(expresion[y]);
}
else
{
objectPila.Push(expresion[y]);
}
break;
case '^':
if(objectPila.Vacia() == 1)
{
objectPila.Push(expresion[y]);
break;
}
if(objectPila.Top() == '(')
{
objectPila.Push(expresion[y]);
break;
}
if(objectPila.Top() == '^')
{
res++;
result[res] = objectPila.Top();
objectPila.Pop();
objectPila.Push(expresion[y]);
}
else
{
objectPila.Push(expresion[y]);
}
break;
default:
res++;
result[res] = expresion[y];
break;
}
}
for(int z = objectPila.getLastPos(); z != -1; z--)
{
res++;
result[res] = objectPila.Top();
objectPila.Pop();
}
cout<<"La conversion a notacion posfija es: ";
for(int z = 0; z <= res; z++)
cout<<result[z];
cout<<"\n";
system("pause");
res = -1;
}while(x == 0);
}
