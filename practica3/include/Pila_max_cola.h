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
    /**
    * @brief Consultar la celda almacenada en el tope de la pila
    * @return Devuelve el valor almacenado en el tope
    */

public:

    /** 
    * @brief Constructor por defecto
    */
    PilaMaxCola();
    /** 
    * @brief Constructor de copia
    * @param otraPila 
    */
    //Constructor de copia
    PilaMaxCola(const PilaMaxCola &otra_pila);

    int getNumElementos();

    void copiar(const PilaMaxCola &otra_pila);

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

    bool vacio() const;

    friend ostream& operator<<(ostream &flujo, const PilaMaxCola &una_pila);

};


#endif // PilaMaxCola_h