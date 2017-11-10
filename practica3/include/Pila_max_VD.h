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

    /** 
    * @brief Constructor por defecto
    */
    PilaMaxVD();
	/** 
    * @brief Constructor de copia
    * @param otraPila 
    */
    //Constructor de copia
    PilaMaxVD(const PilaMaxVD &otra_pila);

    void getNumElementos();

    void copiar(const PilaMaxVD &otra_pila);

    PilaMaxVD& operator=(const PilaMaxVD &otra_pila);


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

    friend ostream& operator<<(ostream &flujo, const PilaMaxVD &una_pila);

};


#endif // PilaMaxVD_h