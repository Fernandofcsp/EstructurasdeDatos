 #include "SongList.h"

 SongsCollection::SongsCollection() {
 Last=-1;
 Deleted=-1;
 }

 bool SongsCollection::isFull() {
 return Last==49;
 }

 bool SongsCollection::isEmpty() {
 return Last==-1;
 }

 bool SongsCollection::isValidPos(const int& Pos) {
 return Pos>-1 and Pos<=Last+1;
 }

 void SongsCollection::insertSong(const std::string& Name, const std::string& Autor, const std::string& Rank) {
 if(isFull()) {
 throw Exception("Desbordamiento de datos, insertSong");
 }
 Last++;
 AllSongs[Last].setSongName(Name);
 AllSongs[Last].setSongAutor(Autor);
 AllSongs[Last].setRanking(Rank);
 }

 void SongsCollection::deleteSong(const int& Pos) {
 if(isEmpty()) {
 throw Exception("Insuficiencia de datos,deleteSong");
 }
 if(!isValidPos(Pos)) {
 throw Exception("Posicion invalida,deleteSong");
 }

 if(Deleted<50) {
 Deleted++;
 DeletedSongs[Deleted].setSongName(AllSongs[Pos].getSongName());
 DeletedSongs[Deleted].setSongAutor(AllSongs[Pos].getSongAutor());
 DeletedSongs[Deleted].setRanking(AllSongs[Pos].getRanking());
 }
 int i = Pos;
 while(i<=Last) {
 AllSongs[i].setSongName(AllSongs[i+1].getSongName());
 AllSongs[i].setSongAutor(AllSongs[i+1].getSongAutor());
 AllSongs[i].setRanking(AllSongs[i+1].getRanking());
 i++;
 }
 Last--;
 }

 std::string SongsCollection::recoverSong(std::string& Name) {
 if(Deleted==-1) {
 throw Exception("Insuficiencia de datos,recoverSong");
 }
 int band;
 for(int i=0; i<=Deleted; i++){
 if(DeletedSongs[i].getSongName() == Name){
 band=i;
 }
 }
 return DeletedSongs[band].toString();
 }

 std::string SongsCollection::firstSong() {
 if(isEmpty()){
 throw Exception("Insuficiencia de datos,firstSong");
 }
 return AllSongs[0].toString();
 }

 std::string SongsCollection::lastSong() {
 if(isEmpty()){
 throw Exception ("Insuficiencia de datos,lastSong");
 }
 return AllSongs[Last].toString();
 }

 std::string SongsCollection::prevSong(const int& Pos) {
 if(isEmpty() or Last==0){
 throw Exception("Insuficiencia de datos,prevSong");
 }
 if(!isValidPos(Pos)){
 throw Exception("Posicion invalida,prevSong");
 }
 return AllSongs[Pos-1].toString();
 }

 std::string SongsCollection::nextSong(const int& Pos) {
 if(isEmpty()){
 throw Exception("Insuficiencia de datos,nextSong");
 }
 if(!isValidPos(Pos)){
 throw Exception("Posicion invalida,nextSong");
 }
 return AllSongs[Pos+1].toString();
 }

 std::string SongsCollection::seeAllSongs(const int& Pos){
 return AllSongs[Pos].toString();
 }

 void SongsCollection::deleteAll() {
 if(isEmpty()){
 throw Exception("Insuficiencia de datos,deleteAll");
 }
 Last=-1;
 Deleted=-1;
 }

 int SongsCollection::getlast(){
 return Last;
 }
