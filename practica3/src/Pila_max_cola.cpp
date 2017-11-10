#include <Pila_max_cola.h>

PilaMaxCola::PilaMaxCola(){};

PilaMaxCola::PilaMaxCola(const PilaMaxCola &otra_pila){
	this->copiar(otra_pila);
}
int PilaMaxCola::getNumElementos(){
	return pila.num_elementos();
}
void PilaMaxCola::copiar(const PilaMaxCola &otra_pila){
	this->pila = otra_pila.pila;
}

PilaMaxCola& PilaMaxCola::operator=(const PilaMaxCola &otra_pila){
	this->copiar(otra_pila);
	return *this;
}

Celda PilaMaxCola::tope() const{
	return pila.frente();
}

void PilaMaxCola::poner(int a_introducir){
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

void PilaMaxCola::quitar(){
	pila.quitar();
}

int PilaMaxCola::elementoTope() const{
	return pila.frente().dato;
}

int PilaMaxCola::maximo() const{
	return pila.frente().max;
}

bool PilaMaxCola::vacio() const{
	return pila.num_elementos()==0;
}

ostream& operator<<(ostream &flujo, const PilaMaxCola &una_pila){
	PilaMaxCola otra_pila;
	otra_pila.copiar(una_pila);
	while(!otra_pila.vacio()){
		flujo << "[" << otra_pila.elementoTope() << ", " << otra_pila.maximo() << "]" <<endl;
		otra_pila.quitar();
	}
	return flujo;
}