#ifndef P1_PROYECTO_H
#define P1_PROYECTO_H

#include <string>
#include <time.h>
using namespace std;

class Proyecto {

private:
    string nombre;
    string area;
    string especialidad;
    string monto;
    string responsable;

public:

    void setNombre(string);
    void setArea(string);
    void setEspecialidad(string);
    void setMonto(string);
    void setResponsable(string);

    string getNombre();
    string getArea();
    string getEspecialida();
    string getMonto();
    string getResponsable();
    string folio(string);


};


#endif
