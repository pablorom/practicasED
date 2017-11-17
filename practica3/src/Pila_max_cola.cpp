#include <Pila_max_cola.h>

PilaMax::PilaMax(){};

PilaMax::PilaMax(const PilaMax &otra_pila){
	this->copiar(otra_pila);
}
int PilaMax::getNumElementos(){
	return pila.num_elementos();
}
void PilaMax::copiar(const PilaMax &otra_pila){
	this->pila = otra_pila.pila;
}

PilaMax& PilaMax::operator=(const PilaMax &otra_pila){
	this->copiar(otra_pila);
	return *this;
}

Celda PilaMax::tope() const{
	return pila.frente();
}

void PilaMax::poner(int a_introducir){
	Celda nueva;
	nueva.dato = a_introducir;
	if(pila.num_elementos()==0){
		nueva.max = a_introducir;
	}else if(pila.frente().max < a_introducir){
		nueva.max = a_introducir; 	
	}else{
		nueva.max = pila.frente().max;
	}

	pila.poner(nueva);
	for(int i=0; i<pila.num_elementos()-1; i++){
		pila.poner(tope());
		pila.quitar();
	}
}

void PilaMax::quitar(){
	pila.quitar();
}

int PilaMax::elementoTope() const{
	return pila.frente().dato;
}

int PilaMax::maximo() const{
	return pila.frente().max;
}

bool PilaMax::vacio() const{
	return pila.num_elementos()==0;
}

ostream& operator<<(ostream &flujo, const PilaMax &una_pila){
	PilaMax otra_pila;
	otra_pila.copiar(una_pila);
	while(!otra_pila.vacio()){
		flujo << "[" << otra_pila.elementoTope() << ", " << otra_pila.maximo() << "]" <<endl;
		otra_pila.quitar();
	}
	return flujo;
}