#include <iostream>
#include <fstream>
#include <string>
#include "Cronologia.h"
#include "Vector_Dinamico.h"
using namespace std;

int main(int argc, char const *argv[]){
	
	if(argc<2){
		cout << "Se necesitan dos ficheros de entrada" << endl;
		return 0;
	}
	ifstream f1(argv[1]);
	if(!f1){
		cout << "No se puede abrir el fichero 1" << argv[1] << endl;
    	return 0;
	}
   
	ifstream f2(argv[2]);
	if(!f2){
		cout << "No se puede abrir el fichero 2" << argv[2] << endl;
		return 0;
	}

	string salida = "union_cronologias";
	ifstream f3(argv[3]);
	if(f3){
		salida = argv[3];
	}
	
	Cronologia cronologia1(argv[1]);
	Cronologia cronologia2(argv[2]);

	//SUMAR CRONOLOGIAS
	cout << "\nSe han unido las dos cronologias en el fichero de salida " << salida << "\n\n";
	Cronologia cronologiaFinal = cronologia1 + cronologia2;
	cronologiaFinal.escribirFichero(salida);

	return 0;
}