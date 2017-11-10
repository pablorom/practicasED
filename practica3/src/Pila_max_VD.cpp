#include "Pila_max_VD.h"

PilaMaxVD::PilaMaxVD(){
	num_celdas = 0;
	pila.resize(num_celdas+5);
}

PilaMaxVD::PilaMaxVD(const PilaMaxVD &otra_pila){
	this->copiar(otra_pila);
}

void PilaMaxVD::getNumElementos(){
	return num_celdas;
}

void PilaMaxVD::copiar(const PilaMaxVD &otra_pila){
	this->pila = otra_pila.pila;
	this->num_celdas = otra_pila.num_celdas;
}

PilaMaxVD& PilaMaxVD::operator=(const PilaMaxVD &otra_pila){
	this->num_celdas = otra_pila.num_celdas;
	this->pila = otra_pila.pila;
}

void PilaMaxVD::poner(int a_introducir){
	if(num_celdas >= pila.size())
		pila.resize(num_celdas+5);

	pila[num_celdas].dato = a_introducir;
	int maximo;
	if(num_celdas==0){
		maximo = a_introducir;
	}else{
		maximo = pila[num_celdas-1].max;
	}
	
	if (a_introducir > maximo)
		maximo = a_introducir;
	pila[num_celdas].max = maximo;
	num_celdas++;
}

void PilaMaxVD::quitar(){
	num_celdas--;
}

Celda PilaMaxVD::tope() const{
	return pila[num_celdas-1];
}

int PilaMaxVD::elementoTope() const{
	Celda tope = this->tope();
	return tope.dato;
}

int PilaMaxVD::maximo() const{
	Celda tope = this->tope();
	return tope.max;
}

bool PilaMaxVD::vacio() const{
	return num_celdas==0;
}

ostream& operator<<(ostream &flujo, const PilaMaxVD &una_pila){
	PilaMaxVD otra_pila;
	otra_pila.copiar(una_pila);
	while(!otra_pila.vacio()){
		flujo << "[" << otra_pila.elementoTope() << ", " << otra_pila.maximo() << "]" <<endl;
		otra_pila.quitar();
	}
	return flujo;
}