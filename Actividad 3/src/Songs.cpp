 #include <cstdio>
 #include "songs.h"

 Songs::Songs() {
 SongAutor="";
 SongName="";
 Ranking="";
 }

 std::string Songs::getSongName() {
 return SongName;
 }

 std::string Songs::getSongAutor() {
 return SongAutor;
 }

 std::string Songs::getRanking() {
 return Ranking;
 }

 void Songs::setSongName(const std::string& Name) {
 SongName = Name;
 }

 void Songs::setSongAutor(const std::string& Autor) {
 SongAutor = Autor;
 }

 void Songs::setRanking(const std::string& Rank) {
 Ranking = Rank;
 }

 std::string Songs::toString() {
 std::string CompleteSong;
 CompleteSong+="Nombre : ";
 CompleteSong+=SongName;
 CompleteSong+="\nAutor : ";
 CompleteSong+=SongAutor;
 CompleteSong+="\nRanking : ";
 CompleteSong+=Ranking;

 return CompleteSong;
 }
