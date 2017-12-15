/**
* \class Cronologia
*
* \brief Clase que implementa todos los metodos del TDA Cronologia.
* 
* Definicion: Cronologia representa cronologias compuestas de varios años y eventos acontecidos en dichos años
*
* \author Ignacio Martinez, Miguel Moraga, Pablo Robles
*
* \date $Date: 2017/10/30
*
*/

#ifndef cRONOLOGIA_H
#define cRONOLOGIA_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Vector_Dinamico.h"
#include "FechaHistorica.h"
using namespace std;


class Cronologia{
	private:

		/// Vector dinamico de fechas historicas
		map<int,FechaHistorica> cronologia;

		/// Util de numero de fechas
		int numFechas;
	public:

		///Crea una cronologia por defecto
		Cronologia();
		
		/**
		* @brief Crea una cronologia con parametros
		* @param nombre nombre del fichero
		*/
		Cronologia(string nombre);
		
		/** 
		* @brief Obtener el numero de fechas de una cronología
		* @return Devuelve un entero con el numero de fechas
		*/
		int getNumFechas() const;

		/** 
		* @brief Añade una fecha historica al vector cronologia
		* @param fecha recibe como entrada un objeto fecha historica
		*
		*/
		void aniadirFecha(FechaHistorica fecha);
		
		/** 
		* @brief Lee cronología de un fichero
		* @param nombre recibe como entrada un nombre de fichero
		*
		*/
		void leerFichero(string nombre);
		
		/** 
		* @brief Escribe en un un fichero
		* @param nombre recibe como entrada un nombre de fichero
		*
		*/
		void escribirFichero(string nombre);
		
		/** 
		* @brief Elimina un año de la cronologia
		* @param anio recibe como entrada el año a eliminar
		*
		*/
		void eliminarAnio(int anio);

		/** 
		* @brief Saber los eventos de un año
		* @param anio recibe como entrada el año del que queremos
		* saber los eventos
		* @return devuelve los eventos del año solicitado
		*/	 
		string eventosEnAnio(int anio);
		
		/** 
		* @brief Crear una subcronologia en un periodo dado
		* @param inicio recibe como entrada el año de inicio
		* @param fin recibe como entrada el año de fin
		* @return devuelve una subcronologia con el periodo dado
		*/
		Cronologia periodoEntre(int inicio, int fin);

		/** 
		* @brief Crear una subcronologia que contenga las fechas
		* que a su vez contienen palabras clave
		* @param palabraClave recibe como entrada una palabra clave
		* @return devuelve una subcronologia con las fechas que contienen la palabra clave
		*/
		Cronologia buscarPalabraClave(string palabraClave);
		

		/** 
		* @brief Da formato a una cronologia para mostrar sus datos
		* @return devuelve todos los datos de la cronologia
		*
		*/
		string toString();
		
		/** 
		* @brief Da formato a una cronologia para mostrar sus datos
		* @return devuelve todos los datos de la cronologia
		*
		*/
		string toString() const;
		
		/** 
		* @brief Operador que combina dos cronologias. Si los años coinciden
		* combina los eventos en una fecha.
		* @param otraCronologia Recibe como entrada una cronologia
		* @return devuelve una subcronologia como resultado de la union de dos cronologias
		*
		*/
		Cronologia operator+(Cronologia &otraCronologia);
		
		/** 
		* @brief Operador para acceder a elementos de una cronologia
		* a traves del año
		* @param anio Recibe como entrada un año
		* @return devuelve un objeto fecha historica
		*
		*/
		FechaHistorica operator[](int anio) ;
		
		/** 
		* @brief Operador para dar salida a una cronologia.
		* @param flujo Recibe como entrada un flujo de salida
		* @param unaCronologia Recibe como entrada un objeto cronologia
		* @return devuelve un flujo de salida
		*
		*/
		friend ostream& operator<<(ostream& flujo, const Cronologia& unaCronologia);

		/** 
		* @brief Muestra un recuento estadistico de los eventos y fechas de una cronologia
		*
		*/
		void recuentoEventos();

};
	
					
#endif
