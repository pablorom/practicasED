#include "Pila_max_cola.h"
#include <iostream>

using namespace std;

int main(){

	PilaMaxCola pila, otra_pila;
	int x;


	for(int i = 0; i < 10; i++){
		cin >> x;
		pila.poner(x);
	}

	otra_pila = pila;

	cout << pila;
	cout << otra_pila;



}