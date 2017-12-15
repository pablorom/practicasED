#include <iostream>
#include <fstream>
#include <string>
#include "Cronologia.h"
#include "Vector_Dinamico.h"
using namespace std;

int main(int argc, char const *argv[]){
	
	if(argc<2){
		cout << "Se necesitan un fichero de entrada" << endl;
		return 0;
	}
	ifstream f1(argv[1]);
	if(!f1){
		cout << "No se puede abrir el fichero 1" << argv[1] << endl;
    	return 0;
	}
   
   	string palabraClave;
   	if(argc < 3){
   		cout << "Introduzca la palabra clave: " << endl;
		cin >> palabraClave;
	}else{
		palabraClave = argv[2];
	}
	
	Cronologia cronologia1(argv[1]);

	Cronologia resultado = cronologia1.buscarPalabraClave(palabraClave);

	string salida = "busqueda_palabra_clave";

	if(argc == 4){
		salida = argv[3];
		resultado.escribirFichero(salida);
	}else{
		cout << "\nFILTRADO PALABRA CLAVE:\n\n";
		cout << resultado.toString() << endl;
	}

	return 0;
}