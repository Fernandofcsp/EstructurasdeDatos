#ifndef CANCION_H
#define CANCION_H
#include <string>
using namespace std;
class Cancion
{
private:
string cancion;
string autor;
int ranking;
public:
void sCancion(string);
void sAutor(string);
void sRanking(const int&);
string gCancion();
string gAutor();
int gRanking();
friend class Lista;

};

#endif // CANCION_H
