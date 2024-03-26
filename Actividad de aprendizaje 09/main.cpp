/*
cout << "----------------Menu----------------" << endl;
cout << "1) Añadir cancion" << endl;
cout << "2) Eliminar cancion" << endl;
cout << "3) Buscar cancion" <<endl;
cout << "4) Otras opciones" << endl;
cout << "5) Salir" << endl;
cout << "Ingresa una opcion" << endl;
*/
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <string>
#include "songs.h"
#include "list.h"
using namespace std;
int main() {
Lista<Cancion> myLista;
Cancion c;
Lista<Cancion>::Nodo* pos;
string myStr;
int op;
char opc,opc2;
do {
cout<<"Lista de canciones Actualmente..."<<endl;
cout << myLista.toString() << endl;
cout<<endl;
cout<<"====Disquera LSLLSE====="<<endl<<endl;
cout<<"1. Insertar cancion"<<endl;
cout<<"2. Eliminar cancion"<<endl;
cout<<"3. Mostrar primera cancion de la lista"<<endl;
cout<<"4. Mostrar ultima cancion de la lista"<<endl;
cout<<"5. Mostrar cancion anterior"<<endl;
cout<<"6. Mostrar cancion siguiente"<<endl;
cout<<"7. Buscar una cancion (lineal)"<<endl;
cout<<"8. Eliminar todo"<<endl;
cout<<"9. Salir"<<endl;
cout<<"Que opcion desea realizar:";
cin>>op;
cin.get();
switch(op) {
case 1:
do {
cout << endl;
cout << " ====INSERTAR CANCION==== "<<endl;
cout << " Nombre de la cancion: "<<endl;
getline(cin,myStr);
c.setNombre(myStr);
cout << "Nombre del interprete:" << endl;
getline(cin, myStr);
c.setAutor(myStr);
cout << "Ranking de la cancion (1-10):" << endl;
cin>>myStr;
c.setRanking(myStr);
try {
pos = myLista.getUltimaPos();
myLista.insertar(pos, c);
}
catch (Lista<Cancion>::Exception ex) {
cout << ex.what() << endl;
break;
}
cout << endl << " cancion insertada exitosamente" << endl << endl;
do {
cout << " Insertar otro? (S/N): ";
cin >> opc;
cin.ignore();
opc = toupper(opc);
}
while(opc != 'S' and opc != 'N');
}
while(opc == 'S');
cout << endl << endl;
system("pause");
system("cls");
break;
case 2:
cout << " ====ELIMINAR CANCION==== "<<endl;
cout << "Nombre de la cancion a eliminar:" << endl;
getline(cin, myStr);
c.setNombre(myStr);
pos = myLista.buscarL(c);
try {
myLista.eliminar(pos);
}
catch (Lista<Cancion>::Exception ex) {
cout << ex.what() << endl;
}
cout << "Cancion Eliminada con exito!!" << endl;
system("pause");
system("cls");
break;
case 3:
cout << " ====PRIMERA CANCION==== "<<endl;
cout << myLista.recuperar(myLista.getPrimeraPos()).toString() << endl;
cout<<endl;
system("pause");
system("cls");
break;
case 4:
cout << " ====ULTIMA CANCION==== "<<endl;
cout <<myLista.recuperar(myLista.getUltimaPos()).toString() << endl;
cout<<endl;
system("pause");
system("cls");
break;
case 5:
cout << " ====ANTERIOR CANCION==== "<<endl;
cout << "Nombre de la cancion para mostrar su anterior:" << endl;
getline(cin, myStr);
c.setNombre(myStr);
pos = myLista.buscarL(c);
try {
cout << myLista.recuperar(myLista.getAnteriorPos(pos)).toString() << endl;
cout<<endl;
}
catch (Lista<Cancion>::Exception ex) {
cout << ex.what() << endl;
}
system("pause");
system("cls");
break;
case 6:
cout << " ====SIGUIENTE CANCION==== "<<endl;
cout << "Nombre de la cancion para mostrar su siguiente:" << endl;
getline(cin, myStr);
c.setNombre(myStr);
endl;
pos = myLista.buscarL(c);
try {
cout << myLista.recuperar(myLista.getSiguientePos(pos)).toString() <<
cout<<endl;
}
catch (Lista<Cancion>::Exception ex) {
cout << ex.what() << endl;
}
cout << endl;
system("pause");
system("cls");
break;
case 7:
cout << " ====BUSCAR CANCION (LINEAL)==== "<<endl;
cout << "Nombre de la cancion a buscar:" << endl;
getline(cin,myStr);
c.setNombre(myStr);
pos = myLista.buscarL(c);
cout<<myLista.recuperar(pos).toString()<<endl;
cout<<endl;
system("pause");
system("cls");
break;
case 8:
cout << " ====ELIMINAR TODO==== "<<endl;
do {
cout << " Seguro de que desea eliminar todo? (S/N): ";
cin >> opc2;
cin.ignore();
opc2 = toupper(opc2);
system("cls");
}
while(opc2 != 'S' and opc2 != 'N');
if(opc2 == 'S') {
try {
myLista.eliminarTodo();
}
catch (Lista<Cancion>::Exception ex) {
cout << ex.what() << endl;
}
}
cout<<"TODO A SIDO ELIMINADO"<<endl;
system("pause");
system("cls");
break;
case 9:
cout<<"Vuelva pronto!!"<<endl;
break;
default:
cout<<"Opcion invalida, vuelva a intentarlo!!"<<endl;
break;
}
}
while (op!=9);
return 0;
}
