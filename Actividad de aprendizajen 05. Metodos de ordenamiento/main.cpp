#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Lista.h"
#include "Musica.h"

using namespace std;
int main() {
setlocale(LC_ALL,"spanish");
Musicbox<Songs> mySongs;
Songs mySong;
char op, op2;
string myString;
int myInt;

cout << "Bienvenido al programa" << endl;
do {
if( mySongs.getLastPos() != -1 )
for( int i(0) ; i <= mySongs.getLastPos() ; i++ )
cout << mySongs.retrieve(i)<< endl;
cout << "----------------Menu----------------" << endl;
cout << "1) Añadir cancion" << endl;
cout << "2) Eliminar cancion" << endl;
cout << "3) Buscar cancion" <<endl;
cout << "4) Ordenar" << endl;
cout << "5) Otras opciones" << endl;
cout << "6) Salir" << endl;
cout << "Ingresa una opcion" << endl;
cin >> op;
op = toupper(op);
switch(op) {
case '1':
cout << "Menu" << endl;
cout << "1) Añadir cancion" << endl;
cout << "2) Añadir desde una posicion" << endl;
cout << "Ingrese una opcion:";
cin >> op;
op = toupper(op);
switch(op) {
case '1':
cin.ignore();
cout << "Ingrese el nombre de la cacion:";
getline(cin,myString);
mySong.setSongName(myString);
cout << "Ingrese el nombre del autor:";
getline(cin,myString);
mySong.setSongAutor(myString);
cout << "Ingrese la posicion en el ranking:";
getline(cin,myString);
mySong.setSongRanking(myString);
try {
mySongs.insertSong(mySongs.getLastPos(),mySong);
}
catch(Exception ex) {
cout << ex.what() << endl;
}
break;
case '2':
cin.ignore();
cout << "Proporcione el nombre de la cacion:";
getline(cin,myString);
mySong.setSongName(myString);
cout << "Proporcione el nombre del autor:";
getline(cin,myString);
mySong.setSongAutor(myString);
cout << "Proporcione la posicion en el ranking:";
getline(cin,myString);
mySong.setSongRanking(myString);
cout << "Proporcione la posicion en que desa añadir:";
cin >> myInt;
try {
mySongs.insertSong(myInt,mySong);
}
catch(Exception ex) {
cout << ex.what() << endl << endl;
}
break;
default:
    cout <<"Opcion invalida" <<endl;
    break;
}
break;
case '2':
cout << "Ingrese que cancion deseas eliminar >> ";
cin >> myInt;
try {
mySongs.deleteMusic(myInt);
}
catch (Exception ex) {
cout << ex.what() << endl << endl;
}
break;
case '3':
    cout << "Menu" << endl;
cout << "1) Busqueda lineal" << endl;
cout << "2) Busqueda binaria" << endl;
cout << "Ingresa una opcion" << endl;
cin >> op;
op = toupper(op);
switch(op) {
case '1':
cin.ignore();
cout << "Ingresa la cancion a buscar >> ";
getline(cin,myString);
mySong.setSongAutor(myString);
mySong.setSongName(myString);
try {
cout << mySongs.retrieve(mySongs.FindDataL(mySong)) << endl;
}
catch( Exception ex ) {
cout << ex.what() << endl;
}
break;
case '2':
cin.ignore();
cout << "Ingresa la cancion a buscar >> ";
getline(cin,myString);
mySong.setSongAutor(myString);
mySong.setSongName(myString);
try {
cout << mySongs.retrieve(mySongs.FindDataB(mySong)) << endl;
}
catch( Exception ex ) {
cout << ex.what() << endl;
}
break;
}
system("pause");
    break;
case '4':
cout << "Menu" << endl;
cout << "A) Por Cancion" << endl;
cout << "B) Por Autor" << endl;
cin >> op;
cin.ignore();
op = toupper(op);
op == 'A' ? op2 = 'A' : op2 = 'B';
cout << "Menu" << endl;
cout << "1) Metodo burbuja" << endl;
cout << "2) Metodo Shell" << endl;
cout << "3) Metodo Insercion" << endl;
cout << "4) Metodo Seleccion" << endl;
cin >> op;
cin.ignore();
op = toupper(op);
switch(op) {
case '1':
try {
mySongs.BubbleSortSongs(op2);
}
catch(Exception ex) {
cout << ex.what() << endl;
}
break;
case '2':
try {
mySongs.ShellSortSongs(op2);
}
catch(Exception ex) {
cout << ex.what() << endl;
}
break;
case '3':
try {
mySongs.InsertSortSongs(op2);
}
catch(Exception ex) {
cout << ex.what() << endl;
}
break;
case '4':
try {
mySongs.SelectSortSongs(op2);
}
catch(Exception ex) {
cout << ex.what() << endl;
}
break;
}
break;



case '5':
  int other;
     cout<<"1.-Primer elemento: "<<endl;
     cout<<"2.-Ultimo elemento: "<<endl;
     cout<<"3.-Elemento anterior: "<<endl;
     cout<<"4.-Siguiente elemento: "<<endl;
     cout<<"5.-Eliminar todo: "<<endl;
     cin>>other;
     if (other==1)
     {
try {
cout << mySongs.retrieve(mySongs.FirstMusic());
}
catch(Exception ex) {
cout << ex.what() << endl;
}
system("pause");
     }
     else if (other==2)
     {
try {
cout << mySongs.retrieve(mySongs.LastMusic());
}
catch(Exception ex) {
cout << ex.what() << endl;
}
system("pause");
     }
     else if (other==3)
     {
cout << "Ingresa la posicion a buscar >> ";
cin >> myInt;
try {
cout << mySongs.retrieve(mySongs.PrevMusic(myInt)) << endl;
}
catch(Exception ex) {
cout << ex.what() << endl;
}
system("pause");

     }
     else if (other==4)
     {
cout << "Ingresa la posicion a buscar >> ";
cin >> myInt;
try {
cout << mySongs.retrieve(mySongs.NextMusic(myInt)) << endl;
}
catch(Exception ex) {
cout << ex.what() << endl;
}
system("pause");

     }
     else if (other==5)
     {
do {
cout << "Estas seguro? [S/N]" << endl;
cin >> op;
op = toupper(op);
if( op == 'S' ) {
try {
mySongs.DeleteAllMusic();
}
catch(Exception ex) {
cout << ex.what() << endl;
}
cout << "Se han eliminado satisfactoriamente" << endl;
}
}
while ( op != 'S' and op != 'N');
system("pause");
     }
     else{
        cout<<"Opcion inexistente"<<endl;
         system("pause");
     }
break;
default:
cout << "Se ha ingresado una opcion incorrecta, intentelo de nuevo" << endl;
}
system("cls");
}
while(op!='6');
return 0;
}
