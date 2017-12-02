/**
* \class FechaHistorica
*
* \brief Clase que implementa todos los metodos del TDA FechaHistorica.
* 
* Definicion: FechaHistorica representa fechas y los eventos que ocurrieron en esas fechas
*
* \author Ignacio Martinez, Miguel Moraga, Pablo Robles
*
* \date $Date: 2017/10/30
*
*/
#ifndef fECHAhISTORICA_H
#define fECHAhISTORICA_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
#include "Vector_Dinamico.h"
using namespace std;


class FechaHistorica{
	private:

	
		pair<int,set<string>> fecha;
		//para acceder al anio, fecha.first
		//para acceder al conjunto de strings fecha.second...

		/// Util de numero de eventos
		int numEventos;			//numEventos no es realmente necesaria, podriamos usar el size de la STL

		/** 
		* @brief Saber si una fecha contiene un evento dado
		* @param evento recibe como entrada un evento
		* @return devuelve verdadero o falso
		*/
		bool tieneEvento(string evento) const;

		
	public:

		///Crea una FechaHistorica por defecto
		FechaHistorica();
		
		/**
		* @brief Crea una fecha historica con parametros
		* @param anio año de la fecha
		*/
		FechaHistorica(int anio);

		int getAnio();

		/** 
		* @brief Obtener numero de eventos de una fecha
		* @return devuelve el numero de eventos
		*/
		int getNumEventos() const;

		/** 
		* @brief Modificar el valor del año de una fecha
		* @param anio recibe como entrada un año
		*/
		void setAnio(int anio);
		
		/** 
		* @brief Añade un evento al vector de eventos
		* @param evento recibe como entrada un evento
		*/
		void aniadirEvento(const string evento);
		
		/** 
		* @brief Da formato a una fecha historica para mostrar sus datos
		* @return devuelve todos los datos de la fecha historica
		*
		*/
		string toString() const;
		
		/** 
		* @brief Elimina el ultimo evento de la fecha
		*
		*/	
		void eliminarUltimoEvento();
		
		/** 
		* @brief Elimina un evento en una posicion dada
		* @param posicion numero de la posicion a eliminar
		*
		*/
		void eliminarEvento(int anio);
		
		/** 
		* @brief Operador para igualar dos fechas historicas
		* @param otraFecha otra fecha con la que igualar
		* @return devuelve una fecha historica
		*/
		FechaHistorica& operator=(const FechaHistorica &otraFecha);
		
		/** 
		* @brief Operador para comaparar dos fechas
		* @param otraFecha otra fecha con la que comaparar
		* @return devuelve verdadero o falso 
		*/
		bool operator<(const FechaHistorica &otraFecha);
		
		/** 
		* @brief Operador para combinar dos fechas historicas
		* @param otraFecha otra fecha con la que combinar
		* @return devuelve una fecha historica
		*/
		FechaHistorica operator+(FechaHistorica &otraFecha);
		
		///Clase amiga Cronologia
		friend class Cronologia;
};
	
					
#endif
