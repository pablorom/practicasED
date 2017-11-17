#include "FechaHistorica.h"

using namespace std;

FechaHistorica::FechaHistorica(){
	setAnio(0);
	this->numEventos = 0;
}


FechaHistorica::FechaHistorica(int anio){
	assert(anio >= 0);
	setAnio(anio);
	this->numEventos = 0;
}



int FechaHistorica::getNumEventos() const{
	return numEventos;
}


void FechaHistorica::setAnio(int anio){
	this->fecha.first = anio;
}


void FechaHistorica::aniadirEvento(string evento){
	fecha.second.insert(evento);
	numEventos++;
}


bool FechaHistorica::tieneEvento(string evento) const{
	return fecha.second.count(evento);			//count devuelve 1 o 0 dependiendo de si lo encuentra
}

	
string FechaHistorica::toString() const{
	string resultado;
	
	resultado += to_string(fecha.first);		//fecha.first es el anio

	set<string>::iterator it;
	for(it = fecha.second.begin(); it != fecha.second.end(); it++)
		resultado += "#" + *it;											//si hay dudas consultar la documentacion de set

	resultado += "\n";
	
	return resultado;
}



FechaHistorica& FechaHistorica::operator=(const FechaHistorica &otraFecha){
	if(this != &otraFecha){
		this->numEventos = otraFecha.numEventos;
		this->fecha.first = otraFecha.first;
		this->fecha.second = otraFecha.second;
	}
	
	return *this;
}


bool FechaHistorica::operator<(const FechaHistorica &otraFecha){
	return(this->fecha.first < otraFecha.fecha.first);
}

FechaHistorica FechaHistorica::operator+(FechaHistorica &otraFecha){

	FechaHistorica resultado(otraFecha.first);
	resultado.second = this->second;
	set<string>::iterator it;
	for(it = otraFecha.second.begin(); it != otraFecha.second.end(); it++)
		resultado.second.insert(*it);

	return resultado;
}

void FechaHistorica::eliminarUltimoEvento(){
	set<string>::iterator it = rbegin();			//mirar documentacion de set
	this->anio.second.erase(it);
}


void FechaHistorica::eliminarEvento(int posicion){
		set<string>::iterator it;
		int i = 0;
		for(it = this->fecha.second.begin(); i < posicion; it++);		//si no se entiende preguntar a Ignacio mejor xD
		this->fecha.second.erase(it);
}
