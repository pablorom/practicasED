#ifndef PilaMaxCola_h
#define PilaMaxCola_h

#include <iostream>
#include "Celda.h"
#include "cola.h"

using namespace std;

class PilaMaxCola{

private:
    
    Cola <Celda> pila;
    int num_celdas;

public:

    /** 
    * @brief Constructor por defecto
    */
    PilaMaxCola();
    /** 
    * @brief Constructor de copia
    * @param otraPila 
    */
    PilaMaxCola(const PilaMaxCola &otra_pila);

    /**
    * @brief Copia los valores de una pila en otra
    * @param otra_pila recibe como parametro un objeto pila por referencia
    */
    void copiar(const PilaMaxCola &otra_pila);
    /** 
    * @brief Operador para igualar dos pilas
    * @param otra_pila recibe como parametro otra pila con la que igualar
    * @return devuelve un objeto de tipo PilaMaxCola
    */
    PilaMaxCola& operator=(const PilaMaxCola &otra_pila);


    /**
    * @brief Poner en la ultima posicion
    * @param a_introducir
    */
    void poner(int a_introducir);
    /**
    * @brief Eliminar tope de la pila
    */
    void quitar();
    /** 
    * @brief Obtener el tope de la pila 
    * @return Devuelve un objeto de tipo Celda como tope de la pila
    */
    Celda tope() const;

    /**
    * @brief Consultar el entero almacenado en la celda tope
    * @return Devuelve el entero tope
    */
    int elementoTope() const;
    /**
    * @brief Devuelve el maximo 
    * @return Devuelve el maximo de toda la pila
    */
    int maximo() const;

    /**
    * @brief Consultar si la pila está vacia
    * @return Devuelve un verdadero o falso en función de que la pila esté o no vacía.
    */
    bool vacio() const;

    /** 
    * @brief Operador para dar salida a los datos almacenados en un objeto PilaMaxCola.
    * @param flujo Recibe como entrada un flujo de salida
    * @param PilaMaxCola Recibe como entrada un objeto PilaMaxCola
    * @return devuelve un flujo de salida
    */
    friend ostream& operator<<(ostream &flujo, const PilaMaxCola &una_pila);

};


#endif // PilaMaxCola_h