
#ifndef __Pila_max_H__
#define __Pila_max_H__
#include "cola.h"
#include "Celda.h"
#include <cassert>

class PilaMaxCola{
  private:
    Cola<Celda> pila;
    int num_elem;

  public:
    /**
    *@brief Constructor por defecto
    */
    PilaMaxCola();
    /**
    *@brief Constructor de copia
    *@param pila_a_copiar Pila de la que va a copiar
    */
    PilaMaxCola(const PilaMaxCola pila_a_copiar);
    /**
    *@brief Destructor
    */
    ~PilaMaxCola();


}
#endif