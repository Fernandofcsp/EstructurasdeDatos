#include "iostream"
#include <climits>
#include <cfloat>
#include <iomanip>
#include "Tabla.h"

using namespace std;

void Tabla::MostrarTamano(){
	cout<<"     Tipo de dato   "<<setw(6)<<"Bits"<<setw(15)<<"Valor minimo"<<setw(18)<<"Valor maximo"<<setw(18)<<endl;
	cout<<"\n\nSigned char       "<<setw(6)<<sizeof(signed char)*CHAR_BIT<<setw(15)<<SCHAR_MIN<<setw(18)<<SCHAR_MAX<<endl;
	cout<<"\n\nUnsigned char     "<<setw(6)<<sizeof(unsigned char)*CHAR_BIT<<setw(15)<<0<<setw(18)<<UCHAR_MAX<<endl;
	cout<<"\n\nSigned short int  "<<setw(6)<<sizeof(signed short int)*CHAR_BIT<<setw(15)<<SHRT_MIN<<setw(18)<<SHRT_MAX<<endl;
	cout<<"\n\nUnsigned short int"<<setw(6)<<sizeof(unsigned short int)*CHAR_BIT<<setw(15)<<0<<setw(18)<<USHRT_MAX<<endl;
	cout<<"\n\nSigned long int   "<<setw(6)<<sizeof(signed long int)*CHAR_BIT<<setw(15)<<LONG_MIN<<setw(18)<<LONG_MAX<<endl;
	cout<<"\n\nUnsigned long int "<<setw(6)<<sizeof(unsigned long int)*CHAR_BIT<<setw(15)<<0<<setw(18)<<ULONG_MAX<<endl;
	cout<<"\n\nFloat             "<<setw(6)<<sizeof(float)*CHAR_BIT<<setw(15)<<FLT_MIN<<setw(18)<<FLT_MAX<<endl;
	cout<<"\n\nDouble            "<<setw(6)<<sizeof(double)*CHAR_BIT<<setw(15)<<DBL_MIN<<setw(18)<<DBL_MAX<<endl;cout<<"\n\n\n\n";

	cout<<"\n\n\n\n";

}
