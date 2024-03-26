#include "Lista.h"
using namespace std;
void Lista::Inicializa()
{
ultimo = -1;
}
int Lista::Vacia ()
{
if(ultimo == -1)
return 1;
else
return 0;
}
int Lista::Llena()
{
if(ultimo == 49)
return 1;
else
return 0;
}
void Lista::Inserta(int p, Cancion m)
{
for(int x = ultimo; x>p; x--)
{

}
}
void Lista::eliminarPos(int)
{

}
Lista::Recupera()
{

}
int Lista::primeraPosicion()
{

}
int Lista::ultimaPosicion()
{

}

int Lista::obtenerPosAnterior(int)
{

}
int Lista::obtenerPosSiguiente(int)
{

}
void Lista::Anular()
{

}
void Lista::Imprimir()
{
if(ultimo != -1)
{
for(int x=0; x <= ultimo; x++)
{
cout<< x+1 << ".- Cancion: "<<valores[x].gCancion();
cout<<"\tAutor: "<<valores[x].gAutor();
cout<<"\tRanking: "<<valores[x].gRanking()<<endl;
}
}
if(ultimo == -1)
{
cout<<"No se encuentra ninguna cancion en la lista\n";
}
}
int Lista::Validar(int p)
{
if(p >= -1 and p <= ultimo + 1)
return 1;
else
return 0;
}


