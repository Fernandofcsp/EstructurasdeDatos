#include "Persona.h"

Persona::Persona()
{
    //ctor
}

Persona::~Persona()
{
    //dtor
}

ostream& operator <<(ostream& os, Persona obj)
{
    os <<obj.Getnombre() <<"|"
    <<obj.Getedad() << "|"
    <<obj.Getpeso() <<endl;
    return os;
}

istream& operator >>(istream& is, Persona& obj)
{
    string aux;
    getline(is, aux, '|');
    if (aux.size() > 0)
    {
        obj.Setnombre(aux);
        getline(is, aux, '|');
        obj.Setedad(stoi(aux));
        getline (is, aux);
        obj.Setpeso(stof(aux));
    }
    return is;
}
