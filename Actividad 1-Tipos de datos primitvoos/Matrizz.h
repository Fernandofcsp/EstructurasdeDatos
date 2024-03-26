#ifndef Matrizz.h
#define Matrizz.h

class Matriz{
	private:
		float matriz1[10][10],matriz2[10][10],suma[10][10],multiplicar[10][10];
		int i,j;

    public:
    	void Tamano(int);
    	void Llenar();
    	void Sumar();
    	void Mostrar();
};





#endif // Matrizz.h
