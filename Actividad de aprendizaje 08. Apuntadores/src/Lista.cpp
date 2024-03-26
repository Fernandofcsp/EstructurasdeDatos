#include "Lista.h"
 Musicbox::Musicbox() {
 Last=-1;
 Deleted=-1;
 }

 bool Musicbox::isFull() {
 return Last==2999;
 }

 bool Musicbox::isEmpty() {
 return Last==-1;
 }

 bool Musicbox::isValidPos(const int& Pos) {
 return Pos>-1 and Pos<=Last+1;
 }

 void Musicbox::insertMusic(const std::string& Name, const std::string& Autor, const std::string& Rank) {
 if(isFull()) {
 throw Exception("Desbordamiento de datos, insertMusic");
 }
 Last++;
 AllMusic[Last].setSongName(Name);
 AllMusic[Last].setSongAutor(Autor);
 AllMusic[Last].setRanking(Rank);
 }

 void Musicbox::deleteMusic(const int& Pos) {
 if(isEmpty()) {
 throw Exception("Insuficiencia de datos,deleteMusic");
 }
 if(!isValidPos(Pos)) {
 throw Exception("Posicion invalida,deleteMusic");
 }

 if(Deleted<50) {
 Deleted++;
 DeletedMusic[Deleted].setSongName(AllMusic[Pos].getSongName());
 DeletedMusic[Deleted].setSongAutor(AllMusic[Pos].getSongAutor());
 DeletedMusic[Deleted].setRanking(AllMusic[Pos].getRanking());
 }
 int i = Pos;
 while(i<=Last) {
 AllMusic[i].setSongName(AllMusic[i+1].getSongName());
 AllMusic[i].setSongAutor(AllMusic[i+1].getSongAutor());
 AllMusic[i].setRanking(AllMusic[i+1].getRanking());
 i++;
 }
 Last--;
 }

 std::string Musicbox::recoverMusic(std::string& Name) {
 if(Deleted==-1) {
 throw Exception("Insuficiencia de datos,recoverMusic");
 }
 int band;
 for(int i=0; i<=Deleted; i++){
 if(DeletedMusic[i].getSongName() == Name){
 band=i;
 }
 }
 return DeletedMusic[band].toString();
 }
 int Musicbox::FindDataB(const std::string& Name) {
if(isEmpty()) {
throw Exception("Insuficiencia de datos, FindDataB");
}
int i=0, j=Last, m;
while(i<=j) {
m = (i + j) / 2;
if( AllMusic[m].getSongName() == Name or AllMusic[m].getSongAutor() == Name) {
return m;
}
if( AllMusic[m].getSongName() < Name or AllMusic[m].getSongAutor() < Name ) {
i= m + 1;
}
else {
j = m - 1;
}
}
return -1;
}
int Musicbox::FindDataL(const std::string& Name) {
if(isEmpty()) {
throw Exception("Insuficiencia de datos, FindDataL");
}
for(int i = 0 ; i <= Last ; i++) {
if( AllMusic[i].getSongName() == Name or AllMusic[i].getSongAutor() == Name ) {
return i;
}
}
return -1;
}

 std::string Musicbox::firstMusic() {
 if(isEmpty()){
 throw Exception("Insuficiencia de datos,firstMusic");
 }
 return AllMusic[0].toString();
 }

 std::string Musicbox::lastMusic() {
 if(isEmpty()){
 throw Exception ("Insuficiencia de datos,lastMusic");
 }
 return AllMusic[Last].toString();
 }

 std::string Musicbox::prevMusic(const int& Pos) {
 if(isEmpty() or Last==0){
 throw Exception("Insuficiencia de datos,prevMusic");
 }
 if(!isValidPos(Pos)){
 throw Exception("Posicion invalida,prevMusic");
 }
 return AllMusic[Pos-1].toString();
 }

 std::string Musicbox::nextMusic(const int& Pos) {
 if(isEmpty()){
 throw Exception("Insuficiencia de datos,nextMusic");
 }
 if(!isValidPos(Pos)){
 throw Exception("Posicion invalida,nextMusic");
 }
 return AllMusic[Pos+1].toString();
 }

 std::string Musicbox::seeAll(const int& Pos){
 return AllMusic[Pos].toString();
 }

 void Musicbox::deleteAll() {
 if(isEmpty()){
 throw Exception("Insuficiencia de datos,deleteAll");
 }
 Last=-1;
 Deleted=-1;
 }

 int Musicbox::getlast(){
 return Last;
 }
