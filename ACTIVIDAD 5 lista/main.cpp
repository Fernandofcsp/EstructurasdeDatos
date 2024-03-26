 #include <windows.h>
 #include <iostream>
 #include <cstdlib>
 #include "Lista.h"

 using namespace std;
 int main()
 {
 setlocale(LC_ALL,"spanish");
 Musicbox pistas;
 char op, op2;
 int Intpos;
 string ncancion, nautor, nraking;
 cout << "Programa, lista de canciones..." << endl ;
 Sleep(500);
 do
{
    system("cls");
 if(pistas.getlast() != -1)
{
for(int x=0; x <= pistas.getlast(); x++)
{
cout<<pistas.seeAll(x)<<endl<<"Posicion: "<<x<<endl<<endl<<endl;
}
}
if(pistas.getlast() == -1)
{
cout<<"No se encuentra ninguna cancion en la lista"<<endl<<endl<<endl;
}
 cout << "----------Menu----------" << endl ;
 cout << "1) Añadir Cancion" << endl;
 cout << "2) Eliminar Cancion" << endl;
 cout << "3) Otras opciones" << endl;
 cout << "4) Buscar cancion" << endl;
 cout << "5) Salir" << endl;
 cin >> op;

 op = toupper(op);

 switch (op) {
 case '1':
 cin.ignore();
 cout << "Ingresa el nombre de la cancion >> ";
 getline(cin,ncancion);
 cout << "Ingresa el nombre del Autor >> ";
 getline(cin,nautor);
 cout << "Ingresa la posicion del ranking >> ";
 cin >> nraking;
 try {
 pistas.insertMusic(ncancion,nautor,nraking);
 } catch(Musicbox::Exception ex) {
 cout << ex.what() << endl;
 }
 cin.ignore();
 break;
 case '2':
 cout << "Ingresa la posicion de la cancion a borrar : ";
 cin>>Intpos;
 try {
 pistas.deleteMusic(Intpos);
 } catch(Musicbox::Exception ex) {
 cout << ex.what() << endl;
 }
 break;
 case '3':
     int other;
     cout<<"1.-Primer elemento: "<<endl;
     cout<<"2.-Ultimo elemento: "<<endl;
     cout<<"3.-Elemento anterior: "<<endl;
     cout<<"4.-Siguiente elemento: "<<endl;
     cout<<"5.-Eliminar todo: "<<endl;
     cout<<"6.-Recuperar elemento: "<<endl;
     cin>>other;
     if (other==1)
     {
    try {
 cout << pistas.firstMusic() << endl << endl;
 } catch(Musicbox::Exception ex) {
 cout << ex.what() << endl;
 }
 system("pause");
     }
     else if (other==2)
     {
    try {
 cout<<pistas.lastMusic() << endl << endl;
 } catch(Musicbox::Exception ex) {
 cout << ex.what() << endl;
 }
  system("pause");
     }
     else if (other==3)
     {
 cout << "Ingresa la posicion para ver el anterior a esta: ";
 cin>>Intpos;
 try {
 cout << pistas.prevMusic(Intpos) << endl << endl;
 } catch(Musicbox::Exception ex) {
 cout << ex. what() << endl << endl << endl;
 }
  system("pause");
     }
     else if (other==4)
     {
 cout << "Ingresa la posicion para ver la siguiente a esta: ";
 cin>>Intpos;
 try {
 cout << pistas.nextMusic(Intpos) << endl << endl;
 } catch(Musicbox::Exception ex) {
 cout << ex. what() << endl << endl << endl;
 }
  system("pause");
     }
     else if (other==5)
     {
 do {
 cout<< "Estas seguro? [S/N] >> ";
 cin>>op2;
 cin.ignore();
 op2 = toupper(op2);
 } while(op2 != 'S' and op2!= 'N');
 if (op2 == 'S')
 pistas.deleteAll();
  system("pause");
     }
     else if (other==6)
     {
 cout << "Proporciona el nombre de la cancion a recuperar: ";
 getline(cin,ncancion);
 try {
 cout << pistas.recoverMusic(ncancion);
 } catch(Musicbox::Exception ex) {
 cout << ex.what() << endl;
 }
  system("pause");
     }
     else{
        cout<<"Opcion inexistente"<<endl;
         system("pause");
     }
    break;
    case '4':
do {
cout << "MenÃº" << endl;
cout << "a) Busqueda binaria" << endl;
cout << "b) Busqueda lineal" << endl;
cout << "c) Regresar" << endl;
cout << "Ingresa una opcion >> ";
cin >> op;
op = toupper(op);
switch(op) {
case 'A':
cin.ignore();
cout << "Ingrese el nombre a buscar >> ";
getline(cin,ncancion);
try {
Intpos = pistas.FindDataB(ncancion);
}
catch (Musicbox::Exception ex) {
cout << ex.what() << endl;
}
if( Intpos == -1 ) {
cout << "No se encontro la cancion" << endl;
}
else {
cout << pistas.seeAll(Intpos) << endl;
}
break;
case 'B':
cin.ignore();
cout << "Ingrese la cancion a buscar >> ";
getline(cin,ncancion);
try {
Intpos = pistas.FindDataL(ncancion);
}
catch (Musicbox::Exception ex) {
cout << ex.what() << endl;
}
if( Intpos == -1 ) {
cout << "No se encontro la cancion" << endl;
}
else {
cout << pistas.seeAll(Intpos) << endl;
}
break;
case 'C':
break;
default:
cout << "Se ha ingresado una opcion incorrecta, intente de nuevo" << endl << endl;
}
}
while(op!='C');
break;

 case '5':
 cout << "Nos vemos..." << endl;
 break;

 default:
 cout << "Error, opcion invalida o inexistente" << endl << endl ;
 }
 } while(op!='4');
 system("pause");
 return 0;
 }
