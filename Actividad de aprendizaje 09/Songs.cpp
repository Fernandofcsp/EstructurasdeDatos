#include "songs.h"
void Songs::setSongName(const std::string& Name) {
SongName = Name;
}
void Songs::setSongAutor(const std::string& Autor) {
SongAutor = Autor;
}
void Songs::setSongRanking(const std::string& Ranking) {
SongRanking = Ranking;
}
std::string Songs::toString() const {
std::string AllSong;
AllSong += SongName;
AllSong += " | ";
AllSong += SongAutor;
AllSong += " | ";
AllSong += SongRanking;
return AllSong;
}
std::string Songs::getSongName() const {
return SongName;
}
std::string Songs::getSongAutor() const {
return SongAutor;
}
std::string Songs::getSongRanking() const {
return SongRanking;
}
bool Songs::operator == (const Songs& Song) const {
return SongName == Song.SongName or SongAutor == Song.SongAutor;
}
bool Songs::operator != (const Songs& Song) const {
return SongName != Song.SongName or SongAutor != Song.SongAutor;
}
bool Songs::operator >= (const Songs& Song) const {
return SongName >= Song.SongName or SongAutor >= Song.SongAutor;
}
bool Songs::operator > (const Songs& Song) const {
return SongName > Song.SongName or SongAutor > Song.SongAutor;
}
bool Songs::operator <= (const Songs& Song) const {
return SongName <= Song.SongName or SongAutor <= Song.SongAutor;
}
bool Songs::operator < (const Songs& Song) const {
return SongName < Song.SongName or SongAutor < Song.SongAutor;
}
std::ostream& operator << (std::ostream& os, Songs& s){
std::string aux;
aux = s.SongName + " | " + s.SongAutor + " | " + s.SongRanking + "\n";
os << aux;
return os;
}
std::istream& operator >> (std::istream& is, Songs& s){
is >> s.SongAutor;
is >> s.SongAutor;
is >> s.SongRanking;
return is;
}
