#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

class Persona
{
    public:
        Persona();
        virtual ~Persona();

        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        int Getedad() { return edad; }
        void Setedad(int val) { edad = val; }
        float Getpeso() { return peso; }
        void Setpeso(float val) { peso = val; }
        ///OutputStream flujo de salida
        friend ostream& operator<<(ostream& os, Persona obj);
        ///InputStream flujo de entrada
        friend istream& operator>>(istream& is, Persona& obj);


    protected:

    private:
        string nombre;
        int edad;
        float peso;
};

#endif // PERSONA_H
