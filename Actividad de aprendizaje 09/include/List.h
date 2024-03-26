#ifndef LIST_H
#define LIST_H
#include <string>
#include <exception>
///Definicion
template <class T>
class Lista {
public:
class Nodo {
private:
T data;
Nodo* siguiente;
Nodo* anterior;
public:
Nodo();
Nodo(const T&);
T& getCancion();
Nodo* getSiguiente() const;
Nodo* getAnterior() const;
void setCancion(const T&);
void setSiguiente(Nodo*);
void setAnterior(Nodo*);
};
class Exception: public std::exception {
private:
std::string msg;
public:
explicit Exception(const char* message) : msg(message) { }
explicit Exception(const std::string& message) : msg(message) { }
virtual ~Exception() throw () { }
virtual const char* what() const throw () {
return msg.c_str();
}
};
private:
Nodo* ancla;
bool posValida(Nodo*);
void copiarTodo(const Lista&);
public:
Lista();
Lista(const Lista&);
~Lista();
bool vacia() const;
void insertar(Nodo*, const T&);
void eliminar(Nodo*);
Nodo* getPrimeraPos() const;
Nodo* getUltimaPos() const;
Nodo* getAnteriorPos(Nodo*) ;
Nodo* getSiguientePos(Nodo*) ;
Nodo* buscarL(const T&) const;
T& recuperar(Nodo*);
std::string toString();
void eliminarTodo();
Lista& operator = (const Lista&);
};
///Implementacion
using namespace std;
///Nodo
template <class T>
Lista<T>::Nodo::Nodo() : siguiente(nullptr), anterior(nullptr) { }
template <class T>
Lista<T>::Nodo::Nodo(const T& e) : data(e), siguiente(nullptr),anterior(nullptr) { }
template <class T>
T& Lista<T>::Nodo::getCancion() {
return data;
}
template <class T>
typename Lista<T>::Nodo* Lista<T>::Nodo::getSiguiente() const {
return siguiente;
}
template <class T>
typename Lista<T>::Nodo* Lista<T>::Nodo::getAnterior() const {
return anterior;
}
template <class T>
void Lista<T>::Nodo::setCancion(const T& e) {
data = e;
}
template <class T>
void Lista<T>::Nodo::setSiguiente(Lista<T>::Nodo* p) {
siguiente = p;
}
template <class T>
void Lista<T>::Nodo::setAnterior(Lista<T>::Nodo* p) {
siguiente = p;
}
///Lista
template <class T>///Validacion de posicion
bool Lista<T>::posValida(Lista<T>::Nodo* p) {
Nodo* aux(ancla);
while(aux != nullptr) {
if(aux == p) {
return true;
}
aux = aux->getSiguiente();
}
return false;
}
template <class T>///Copiar Lista
void Lista<T>::copiarTodo(const Lista<T>& l) {
Nodo* aux(l.ancla);
Nodo* ultimoInsertado(nullptr);
Nodo* newNodo;
while(aux != nullptr) {
newNodo = new Nodo(aux->getCancion());
if(newNodo == nullptr) {
throw Exception("Memoria no disponible, copiarTodo");
}
if(ultimoInsertado == nullptr) {
ancla = newNodo;
}
else {
ultimoInsertado->setSiguiente(newNodo);
newNodo->setAnterior(ultimoInsertado);
}
ultimoInsertado = newNodo;
aux = aux->getSiguiente();
}
}
template <class T>
Lista<T>::Lista() : ancla(nullptr) { }
template <class T>
Lista<T>::Lista(const Lista<T>& l): ancla(nullptr) {
copiarTodo(l);
}
template <class T>
Lista<T>::~Lista() {
eliminarTodo();
}
template <class T>
Lista<T>& Lista<T>::operator = (const Lista<T>& l) {
eliminarTodo();
copiarTodo(l);
return *this;
}
template <class T>
bool Lista<T>::vacia() const {
return ancla == nullptr;
}
template <class T>
void Lista<T>::insertar(Lista<T>::Nodo* p, const T& e) {
if(p != nullptr and !posValida(p)) {
throw Exception(" Posicion invalida, insertar");
}
Nodo* aux(new Nodo(e));
if(aux == nullptr) {
throw Exception(" Memoria no disponible, insertar");
}
if(p == nullptr) {
aux->setSiguiente(ancla);
if(ancla != nullptr) {
ancla->setAnterior(aux);
}
ancla = aux;
}
else {
aux->setAnterior(p);
aux->setSiguiente(p->getSiguiente());
if(aux->getSiguiente()!= nullptr) {
aux->getSiguiente()->setAnterior(aux);
}
p->setSiguiente(aux);
}
}
template <class T>
void Lista<T>::eliminar(Lista<T>::Nodo* p) {
if(!posValida(p)) {
throw Exception(" Posicion invalida, Eliminar.");
}
if(p->getAnterior()!= nullptr) {
p->getAnterior()->setSiguiente(p->getSiguiente());
}
if(p->getSiguiente()!= nullptr) {
p->getSiguiente()->setAnterior(p->getAnterior());
}
if(p == ancla) {
ancla = ancla->getSiguiente();
}
delete p;
}
template <class T>
typename Lista<T>::Nodo* Lista<T>::getPrimeraPos() const {
return ancla;
}
template <class T>
typename Lista<T>::Nodo* Lista<T>::getUltimaPos() const {
if(vacia()) {
return nullptr;
}
Nodo* aux(ancla);
while(aux->getSiguiente() != nullptr) {
aux = aux->getSiguiente();
}
return aux;
}
template <class T>
typename Lista<T>::Nodo* Lista<T>::getAnteriorPos(Lista<T>::Nodo* p) {
if(!posValida(p)) {
return nullptr;
}
return p->getAnterior();
}
template <class T>
typename Lista<T>::Nodo* Lista<T>::getSiguientePos(Lista<T>::Nodo* p) {
if(!posValida(p)) {
return nullptr;
}
return p->getSiguiente();
}
template <class T>
typename Lista<T>::Nodo* Lista<T>::buscarL(const T& e) const {
Nodo* aux(ancla);
while(aux != nullptr and aux->getCancion() != e) {
aux = aux->getSiguiente();
}
return aux;
}
template <class T>
T& Lista<T>::recuperar(Lista<T>::Nodo* p) {
if(!posValida(p)) {
throw Exception(" Posicion invalida, recupera");
}
return p->getCancion();
}
template <class T>
std::string Lista<T>::toString() {
std::string result;
Nodo* aux(ancla);
while(aux != nullptr) {
result += aux->getCancion().toString();
aux = aux->getSiguiente();
}
return result;
}
template <class T>
void Lista<T>::eliminarTodo() {
Nodo* aux;
while(ancla != nullptr) {
aux = ancla;
ancla = ancla->getSiguiente();
delete aux;
}
}
#endif // LIST_H
