#include "Cronologia.h"
using namespace std;


/**
 * @brief Constructor sin parámetros
 */
Cronologia::Cronologia(){
	numFechas = 0;
}


/**
 * @brief Constructor con parámetros
 * @param nombre String con el nombre del fichero a leer
 */
Cronologia::Cronologia(string nombre){
	numFechas = 0;
	leerFichero(nombre);
}



/**
 * @brief 
 */
int Cronologia::getNumFechas() const{
	return this->numFechas;
}
 
 
void Cronologia::aniadirFecha(FechaHistorica fecha){
	if(numFechas >= fechas.size())
		fechas.resize(numFechas + 5);
	
	fechas[numFechas] = fecha;
	numFechas++;
}


void Cronologia::leerFichero(string nombre){
	ifstream fi(nombre);
	char c;
	
	//// Bucle con centinela, actúa hasta que el fichero termine
	fi.get(c);
	while(!fi.eof()){
	
		//// Extraemos un año del flujo. Damos por hecho que toda línea empezará así
		string anioTmp;		
		while(c != '#'){
			anioTmp += c;
			fi.get(c);
		}
		FechaHistorica fechaTmp(atoi(anioTmp.c_str()));
		
		//// Bucle que lee los eventos de una fecha. Damos por hecho que, si hay una, esta tendrá eventos
		do{
			fi.get(c);
			string eventoTmp;
			
			//// Bucle que lee cada uno de los eventos, hasta encontrar algún separador
			while(c != '#' && c != '\n' && !fi.eof()){
				eventoTmp += c;
				fi.get(c);
				if(c == '\r')
					fi.get(c);
			}
			fechaTmp.aniadirEvento(eventoTmp);
		}while(c != '\n' && !fi.eof());
		aniadirFecha(fechaTmp);
		fi.get(c);
	}
	fi.close();
}

void Cronologia::escribirFichero(string nombre){
	ofstream fi(nombre);
	string contenido=this->toString();
	fi << contenido;
	fi.close();
}


void Cronologia::insertarFecha(FechaHistorica unaFecha){
	int posicion = 0;
	while(fechas[posicion].anio < unaFecha.anio && posicion < numFechas){
		posicion++;
	}
	
	//Si ya está ese año solo añadimos eventos
	if(fechas[posicion].anio == unaFecha.anio){
		fechas[posicion]=fechas[posicion]+unaFecha;
	}
	
	else{
		numFechas++;
		//Movemos a la derecha
		for(int i=numFechas-1; i>posicion; i--){
			fechas[i+1]=fechas[i];
		}
		//Lo insertamos en su lugar
		fechas[posicion]=unaFecha;
	}
}



void Cronologia::eliminarAnio(int anio){
	int posicion = posicionAnio(anio);
	assert(posicion > 0);

	for(int i = posicion; i < numFechas-1; i++)
		fechas[i] = fechas[i+1];
	numFechas--;
}


int Cronologia::posicionAnio(int anio){
	bool encontrado = false;
	int posicion = -1;
	
	int i = 0;
	while(i < numFechas && !encontrado){
		if(fechas[i].anio == anio){
			posicion = i;
			encontrado = true;
		}
		i++;
	}
	
	return posicion;
}


string Cronologia::eventosEnAnio(int anio){
	string resultado;
	int posicion = posicionAnio(anio);
	
	if(posicion == -1)
		resultado = "No se encontró el año";
	else
		resultado = fechas[posicion].toString();
		
	return resultado;
}


Cronologia Cronologia::periodoEntre(int inicio, int fin){
	assert(inicio <= fin);
	Cronologia resultado;

	for(int i = 0; i < numFechas; i++){
		if(inicio <= fechas[i].anio && fechas[i].anio <= fin){
			resultado.aniadirFecha(fechas[i]);
		}
	}
	
	return resultado;
}


Cronologia Cronologia::buscarPalabraClave(string palabraClave){
	Cronologia resultado;
	int posicion_encontrada = -1, eventos_encontrados = 0;
	
	for(int i = 0; i < numFechas; i++){
		FechaHistorica fecha_a_introducir;
		for(int j = 0; j < fechas[i].numEventos; j++){
			posicion_encontrada = (fechas[i].eventos[j]).find(palabraClave);
			if(posicion_encontrada != -1){
				fecha_a_introducir.setAnio(fechas[i].anio);
				fecha_a_introducir.aniadirEvento(fechas[i].eventos[j]);
				eventos_encontrados++;
			}
			posicion_encontrada = -1;
		}
		if (eventos_encontrados > 0)
			resultado.aniadirFecha(fecha_a_introducir);
		eventos_encontrados = 0;
	}
	return resultado;
	
}
 
 
string Cronologia::toString(){
	string resultado;
	
	for(int i = 0; i < numFechas; i++){
		resultado += fechas[i].toString();
	}
		
	return resultado;
}


string Cronologia::toString() const{
	string resultado;
	
	for(int i = 0; i < numFechas; i++){
		resultado += fechas[i].toString();
	}
		
	return resultado;
}



Cronologia Cronologia::operator+(Cronologia &otraCronologia){
	Cronologia resultado;
	int i = 0, j = 0;
	
	while(i < (this->numFechas) && j < (otraCronologia.numFechas)){
		if((this->fechas[i]) < (otraCronologia.fechas[j])){
			resultado.aniadirFecha(this->fechas[i]);
			i++;
		}
		
		else if((otraCronologia.fechas[j]) < (this->fechas[i])){
			resultado.aniadirFecha(otraCronologia.fechas[j]);
			j++;
		}
		
		else{
			resultado.aniadirFecha((otraCronologia.fechas[j]) + (this->fechas[i]));
			i++;
			j++;
		}
	}
	
	while(i < (this->numFechas)){
		resultado.aniadirFecha(this->fechas[i]);
		i++;
	}
	
	while(j < (otraCronologia.numFechas)){
		resultado.aniadirFecha(otraCronologia.fechas[j]);
		j++;
	}

	return resultado;
}


FechaHistorica Cronologia::operator[](int anio){
	FechaHistorica resultado(anio);
	
	if(posicionAnio(anio) != -1)
		resultado = fechas[posicionAnio(anio)];
		
	return resultado;
}

void Cronologia::ordenarCronologia(){
	int i,j;
	FechaHistorica tmp;
 
    for (i = 1; i < numFechas; i++){
		tmp = fechas[i];
        j = i - 1;
        while (j >= 0 && tmp < fechas[j]){
			fechas[j + 1] = fechas[j];
            j--;
        }
             
        fechas[j + 1] = tmp;
    }   	
}

ostream& operator<<(ostream &flujo, const Cronologia &unaCronologia){
	flujo << unaCronologia.toString();
	
	return flujo;
}
