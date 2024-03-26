#include "Proyecto.h"
#include <string>

using namespace std;

void Proyecto::setNombre(string nombre) {
    this -> nombre = nombre;
}

void Proyecto::setArea(string area) {
    this -> area = area;
}

void Proyecto::setEspecialidad(string especialidad) {
    this -> especialidad = especialidad;
}

void Proyecto::setMonto(string monto) {
    this -> monto = monto;
}

void Proyecto::setResponsable(string responsable) {
    this -> responsable = responsable;
}

string Proyecto::getNombre() {
    return nombre;
}

string Proyecto::getArea() {
    return area;
}

string Proyecto::getEspecialida() {
    return especialidad;
}

string Proyecto::getMonto() {
    return monto;
}

string Proyecto::getResponsable() {
    return responsable;
}

string Proyecto::folio(string nombre) {

     string nombreL = nombre;

     srand((unsigned)time(NULL));
     int num = rand()%100+1;
     string number = to_string(num);
     string folio = nombreL.substr(0,3)+"-"+number;

    return  folio;
}
