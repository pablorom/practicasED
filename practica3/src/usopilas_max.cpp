#include <iostream>
#include "Pila_max.h"

using namespace std;


int main(){
	PilaMax pila1, pila2;
	int elem;
	for(int i=10; i>=0; i--){
		cin >> elem;
		pila1.poner(elem);
	}
	
	cout << pila1;

	cout << "Se copia pila1 en pila2" <<endl;

	pila2=pila1;

	while (!pila2.vacio()){
		int x = pila2.elementoTope();
		cout << x <<endl;
		pila2.quitar();
	}

return 0;
}