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
		cout << "No se puede abrir el fichero 1" << argv[1] << endl;
    	return 0;
	}
   
   	Cronologia cronologia1(argv[1]);
   	Cronologia subCron;

   	if(argc < 4){
   		cout << "Se necesitan dos años para el intervalo" << endl;
		return 0;
	}else{
		string a,b;
		int anioInicio, anioFin;
		//SUBCRONOLOGIA ENTRE DOS AÑOS
		a=argv[2];
		b=argv[3];
		anioInicio = atoi(a.c_str());
		anioFin = atoi(b.c_str());
		subCron = cronologia1.periodoEntre(anioInicio, anioFin);
	}
	
	string salida = "busqueda_palabra_clave";

	if(argc == 5){
		salida = argv[4];
		subCron.escribirFichero(salida);
	}else{
		cout << "\nFILTRADO POR INTERVALO:" << endl;
		cout << subCron.toString() << endl;
	}

	return 0;
}