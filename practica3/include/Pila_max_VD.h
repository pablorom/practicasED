#ifndef PilaMaxVD_h
#define PilaMaxVD_h

#include "Celda.h"
#include "Vector_Dinamico.tpp"

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
    PilaMaxVD(const PilaMaxVD otra_pila);

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
    * @brief Consultar el entero almacenado en la celda tope
    * @return Devuelve el entero tope
    */
    int elementoTope();
    /**
    * @brief Devuelve el maximo 
    * @return Devuelve el maximo de toda la pila
    */
    int maximo();

    bool vacio();

};


#endif // PilaMaxVD_h