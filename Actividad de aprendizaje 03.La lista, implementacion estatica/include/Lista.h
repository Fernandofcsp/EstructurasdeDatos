#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Cancion.h"
#define MAXIMO 50
    class Lista
{
    private:
    Cancion valores[MAXIMO];
    int ultimo;

    public:
    void Inicializa();
    int Vacia();
    int Llena();
    int Validar(int);
    int primeraPosicion();
    int ultimaPosicion();
    void Inserta(int, Cancion);
    void eliminarPos(int);
    int obtenerPosAnterior(int);
    int obtenerPosSiguiente(int);
    void Imprimir();
    Cancion Recupera(int);
    void Anular();
};


#endif // LISTA_H
