#include "Cancion.h"
using namespace std;
void Cancion::sCancion(string s)
{
cancion = s;
}
void Cancion::sAutor(string a)
{
autor = a;
}
void Cancion::sRanking(const int& r)
{
ranking = r;
}
string Cancion::gCancion()
{
return cancion;
}
string Cancion::gAutor()
{
return autor;
}
int Cancion::gRanking()
{
return ranking;
}
