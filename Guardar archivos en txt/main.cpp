#include <iostream>
#include "Persona.h"
#include <fstream> ///FileStream ~ Flujo de archivos
using namespace std;

int main()
{
    ///OutputFileStream ~ Flujo de salida al archivo
    ///ios::app ~ append ~ agregar
    ofstream salida("archivo.txt", ios::app);
    ifstream entrada ("archivo.txt");
    Persona per1;

    per1.Setnombre("QQ");
    per1.Setedad(11);
    per1.Setpeso(11.11);
    cout << per1 << endl;
    if (!salida.is_open())
        cout<<"Error en el archivo de salida" <<endl;
        else
        {
            salida<< per1;
            salida.close();
        }
if (!entrada.is_open())
    cout<<"Error en el archivo de entrada" <<endl;
else
{
    while(entrada >> per1)
        cout<<per1<<endl;
    entrada.close();
}
    return 0;
}
