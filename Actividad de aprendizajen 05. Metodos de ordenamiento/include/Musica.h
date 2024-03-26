#ifndef MUSICA_H
#define MUSICA_H
#include <string>
#include <iostream>
#include <string>
class Songs {
private:
std::string SongName;
std::string SongAutor;
std::string SongRanking;
public:
void setSongName(const std::string&);
void setSongAutor(const std::string&);
void setSongRanking(const std::string&);
std::string toString() const;
std::string getSongName() const;
std::string getSongAutor() const;
std::string getSongRanking() const;
bool operator == (const Songs&) const;
bool operator != (const Songs&) const;
bool operator >= (const Songs&) const;
bool operator > (const Songs&) const;
bool operator <= (const Songs&) const;
bool operator < (const Songs&) const;
friend std::ostream& operator << (std::ostream&, Songs&);
friend std::istream& operator >> (std::istream&, Songs&);
};
#endif // MUSICA_H
