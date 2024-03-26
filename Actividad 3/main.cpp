 #include <windows.h>
 #include <iostream>
 #include <cstdlib>
 #include "SongList.h"

 using namespace std;
 int main()
 {
 setlocale(LC_ALL,"spanish");
 SongsCollection mySong;
 char op, op2;
 int myInt2;
 string myString, myString2, myString3;
 cout << "Programa, lista de canciones..." << endl ;
 Sleep(500);
 do
{
    system("cls");
 if(mySong.getlast() != -1)
{
for(int x=0; x <= mySong.getlast(); x++)
{
cout<<"Posicion: "<<x<<endl<<mySong.seeAllSongs(x)<<endl<<endl<<endl;
}
}
if(mySong.getlast() == -1)
{
cout<<"No se encuentra ninguna cancion en la lista"<<endl<<endl<<endl;
}
 cout << "----------Menu----------" << endl ;
 cout << "1) Añadir Cancion" << endl;
 cout << "2) Eliminar Cancion" << endl;
 cout << "3) Otras opciones" << endl;
 cout << "4) Salir" << endl;
 cin >> op;

 op = toupper(op);

 switch (op) {
 case '1':
 cin.ignore();
 cout << "Ingresa el nombre de la cancion >> ";
 getline(cin,myString);
 cout << "Ingresa el nombre del Autor >> ";
 getline(cin,myString2);
 cout << "Ingresa la posicion del ranking >> ";
 cin >> myString3;
 try {
 mySong.insertSong(myString,myString2,myString3);
 } catch(SongsCollection::Exception ex) {
 cout << ex.what() << endl;
 }
 cin.ignore();
 break;
 case '2':
 cout << "Ingresa la posicion de la cancion a borrar : ";
 cin>>myInt2;
 try {
 mySong.deleteSong(myInt2);
 } catch(SongsCollection::Exception ex) {
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
 cout << mySong.firstSong() << endl << endl;
 } catch(SongsCollection::Exception ex) {
 cout << ex.what() << endl;
 }
 system("pause");
     }
     else if (other==2)
     {
    try {
 cout<<mySong.lastSong() << endl << endl;
 } catch(SongsCollection::Exception ex) {
 cout << ex.what() << endl;
 }
  system("pause");
     }
     else if (other==3)
     {
 cout << "Ingresa la posicion para ver el anterior a esta: ";
 cin>>myInt2;
 try {
 cout << mySong.prevSong(myInt2) << endl << endl;
 } catch(SongsCollection::Exception ex) {
 cout << ex. what() << endl << endl << endl;
 }
  system("pause");
     }
     else if (other==4)
     {
 cout << "Ingresa la posicion para ver la siguiente a esta: ";
 cin>>myInt2;
 try {
 cout << mySong.nextSong(myInt2) << endl << endl;
 } catch(SongsCollection::Exception ex) {
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
 mySong.deleteAll();
  system("pause");
     }
     else if (other==6)
     {
 cout << "Proporciona el nombre de la cancion a recuperar: ";
 getline(cin,myString);
 try {
 cout << mySong.recoverSong(myString);
 } catch(SongsCollection::Exception ex) {
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
 cout << "Nos vemos..." << endl;
 break;

 default:
 cout << "Error, opcion invalida o inexistente" << endl << endl ;
 }
 } while(op!='4');
 system("pause");
 return 0;
 }
