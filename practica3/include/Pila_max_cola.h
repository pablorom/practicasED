/**
* @class PilaMax
*
* @brief Clase que posee todos los metodos basicos 
* de una pila impleventada con una cola.
* 
* Definicion: PilaMax representa una pila y todas sus funcionalidades básicas implementada internamente con una cola.
*
* @author Ignacio Martinez, Miguel Moraga, Pablo Robles
*
* @date 13/11/2017
*
*/
#ifndef Pila_max_cola_h
#define Pila_max_cola_h

#include <iostream>
#include "Celda.h"
#include "cola.h"

using namespace std;

class PilaMax{

private:
    
    Cola <Celda> pila;
    int num_celdas;

public:

    /** 
    * @brief Constructor por defecto
    */
    PilaMax();
    /** 
    * @brief Constructor de copia
    * @param otraPila 
    */
    PilaMax(const PilaMax &otra_pila);

    /** 
    * @brief Consultar numero de elementos de la pila
    * @return un entero como numero de elementos de la pila 
    */
    int getNumElementos();

    /**
    * @brief Copia los valores de una pila en otra
    * @param otra_pila recibe como parametro un objeto pila por referencia
    */
    void copiar(const PilaMax &otra_pila);
    /** 
    * @brief Operador para igualar dos pilas
    * @param otra_pila recibe como parametro otra pila con la que igualar
    * @return devuelve un objeto de tipo PilaMax
    */
    PilaMax& operator=(const PilaMax &otra_pila);


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
    * @brief Operador para dar salida a los datos almacenados en un objeto PilaMax.
    * @param flujo Recibe como entrada un flujo de salida
    * @param PilaMax Recibe como entrada un objeto PilaMax
    * @return devuelve un flujo de salida
    */
    friend ostream& operator<<(ostream &flujo, const PilaMax &una_pila);

};


#endif // PilaMax_h