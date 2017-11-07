#include "Pila_max_VD.h"

PilaMaxVD::PilaMaxVD(){
	num_celdas = 0;
}

PilaMaxVD::PilaMaxVD(const Pila_max_VD otra_pila){
	this->copiar(otra_pila);
}

PilaMaxVD::copiar(const Pila_max_VD otra_pila){
	this->pila = otra_pila.pila;
	this->num_celdas = otra_pila.num_celdas;
}

void PilaMaxVD::poner(int a_introducir){
	pila[num_celdas].dato = a_introducir;
	int maximo = Pila_max_VD[num_celdas-1].max;
	if (a_introducir > maximo)
		maximo = a_introducir;
	pila[num_celdas].max = maximo;
	num_celdas++;
}

void PilaMaxVD::quitar(){
	num_celdas--;
}

Celda PilaMaxVD::tope(){
	return pila[num_celdas-1];
}

int PilaMaxVD::elementoTope(){
	Celda tope = tope();
	return tope.dato;
}

int PilaMaxVD::maximo(){
	Celda tope = tope();
	return tope.max;
}

bool PilaMaxVD::vacio(){
	return num_celdas==0;
}