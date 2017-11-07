#include "Pila_max_VD.h"
#include <iostream>

using namespace std;

int main(){
	PilaMaxVD pila;
	int x;

	for(int i = 0; i < 10; i++){
		cin >> x;
		pila.poner(x);
	}
	while(!pila.vacio()){
		cout << pila.elementoTope();
		cout << "->max: " << pila.maximo() << endl;
		pila.quitar();
	}


}