#include <iostream>
#include <fstream>
#include <string>
#include "Cronologia.h"
#include "Vector_Dinamico.h"
using namespace std;


int main(int argc, char* argv[]){
	
	
	if(argc<2){
		cout << "Dime el nombre del fichero con la cronología" << endl;
		return 0;
	}
	ifstream f1(argv[1]);
	if(!f1){
		cout << "No se puede abrir el fichero " << argv[1] << endl;
    	return 0;
	}
   
	ifstream f2(argv[2]);
	if(!f2){
		cout << "No se puede abrir el fichero " << argv[2] << ", deberían proporcionarse dos ficheros.";
		return 0;
	}
	
	Cronologia cronologia1(argv[1]);
	Cronologia cronologia2(argv[2]);
	
	char opcion='x';
	while(opcion != 'S'){
		
		cout << "\n\n/////////////////////////////////////////////" << endl
			 << "\n\n 			MENU" << endl
			 << "\n\n/////////////////////////////////////////////" << endl
			 << "\n\nSi desea sumar las cronologias 1 y 2 pulse a" << endl
			 << "Si desea hacer una busqueda por año en la cronologia 1 pulse b" << endl
			 << "Si desea hacer una busqueda por palabra en la cronologia 1 pulse c" << endl
			 << "Si desea obtener una sobcronologia entre años en la cronologia 2 pulse d" << endl
			 << "Si desea obtener el recuento estadistico de cronologia1 pulse e" << endl
			 << "Si desea imprimir la cronologia 2 en un fichero pulse f\n\n" << endl
			 << "Para salir del menu pulse S\n\n" << endl;
		cin >> opcion;
		
		if(toupper(opcion) == 'A'){
			//SUMAR CRONOLOGIAS
			cout << "\nSUMAR CRONOLOGIAS\n\n";
			Cronologia cronologiaFinal = cronologia1 + cronologia2;
			cout << cronologiaFinal.toString();
		}
		if (toupper(opcion) == 'B'){
			int anioBusqueda;
			//BUSQUEDA POR AÑO
			cout <<"\nBUSQUEDA POR AÑO\n\n";
			cout << "Introduzca el año en el que buscar: ";
			cin >> anioBusqueda;
			cout << endl << cronologia1[anioBusqueda].toString();
		}
		
		if (toupper(opcion) == 'C'){
			//BUSCAR PALABRA CLAVE
			string palabraClave;
			cout << "\nBUSCAR PALABRA CLAVE:\n\n"
				 << "Introduzca la palabra clave: ";
			cin >> palabraClave;
			Cronologia resultado = cronologia1.buscarPalabraClave(palabraClave);
			cout << resultado.toString();
		}

		if (toupper(opcion) == 'D'){
			int anioInicio, anioFin;
			//SUBCRONOLOGIA ENTRE DOS AÑOS
			cout << "\nSUBCRONOLOGIA ENTRE DOS AÑOS:\n\n"
				 << "Introduzca los años: ";
			cin >> anioInicio;
			cin >> anioFin;
			Cronologia subCron = cronologia1.periodoEntre(anioInicio, anioFin);
			cout << subCron.toString();
		}	
		if (toupper(opcion) == 'E'){
			cronologia1.recuentoEventos();
		}
		if (toupper(opcion) == 'F'){
			//ESCRIBIR EN FICHERO
			Cronologia cronologiaFinal;
			ofstream fich("output.txt");
			fich << cronologiaFinal;
			fich.close();
		}
		
	}
   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */ 
}
