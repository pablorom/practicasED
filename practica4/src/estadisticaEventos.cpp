#include <iostream>
#include <fstream>
#include <string>
#include "Cronologia.h"
#include "Vector_Dinamico.h"
using namespace std;

int main(int argc, char const *argv[]){
	
	if(argc<2){
		cout << "Se necesita un fichero de entrada" << endl;
		return 0;
	}
	ifstream f1(argv[1]);
	if(!f1){
		cout << "No se puede abrir el fichero" << argv[1] << endl;
    	return 0;
	}
   
   	Cronologia cronologia1(argv[1]);

	cronologia1.recuentoEventos();

	return 0;
}