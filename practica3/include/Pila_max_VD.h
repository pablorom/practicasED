/**
* @class PilaMaxVD
*
* @brief Clase que posee todos los metodos basicos 
* de una pila impleventada con un vector dinámico.
* 
* Definicion: PilaMaxVD representa una pila y todas sus funcionalidades básicas implementada internamente con un vector dinámico.
*
* @author Ignacio Martinez, Miguel Moraga, Pablo Robles
*
* @date 13/11/2017
*
*/
#ifndef PilaMaxVD_h
#define PilaMaxVD_h

#include <iostream>
#include "Celda.h"
#include "Vector_Dinamico.h"

using namespace std;

class PilaMaxVD{

private:
    
    Vector_Dinamico<Celda> pila;
    int num_celdas;
    /**
    * @brief Consultar la celda almacenada en el tope de la pila
    * @return Devuelve el valor almacenado en el tope
    */
    Celda tope(); 

public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    PilaMaxVD();
	/** 
    * @brief Constructor de copia
    * @param otra_pila recibe como parametro otra pila para copiar
    */
    PilaMaxVD(const PilaMaxVD &otra_pila);

    /**
    * @brief Copia los valores de una pila en otra
    * @param otra_pila recibe como parametro un objeto pila por referencia
    */
    void copiar(const PilaMaxVD &otra_pila);

    /** 
	* @brief Operador para igualar dos pilas
	* @param otra_pila recibe como parametro otra pila con la que igualar
	* @return devuelve un objeto de tipo PilaMaxVD
	*/
    PilaMaxVD& operator=(const PilaMaxVD &otra_pila);

    /**
    * @brief Poner en la ultima posicion
    * @param a_introducir recbe un entero
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
    * @return Devuelve un entero como el dato de la celda tope
    */
    int elementoTope() const;

    /**
    * @brief Consultar el maximo de la pila
    * @return Devuelve un entero de la ultima celda como el maximo de toda la pila
    */
    int maximo() const;

    /**
    * @brief Consultar si la pila está vacia
    * @return Devuelve un verdadero o falso en función de que la pila esté o no vacía.
    */
    bool vacio() const;

    /** 
	* @brief Operador para dar salida a los datos almacenados en un objeto PilaMaxVD.
	* @param flujo Recibe como entrada un flujo de salida
	* @param PilaMaxVD Recibe como entrada un objeto PilaMaxVD
	* @return devuelve un flujo de salida
	*/
    friend ostream& operator<<(ostream &flujo, const PilaMaxVD &una_pila);

};


#endif // PilaMaxVD_h