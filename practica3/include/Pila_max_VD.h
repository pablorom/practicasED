#ifndef PilaMaxVD_h
#define PilaMaxVD_h

#include "Celda.h"
#include "Vector_Dinamico.tpp"

class PilaMaxVD{

private:
    
    Vector_Dinamico<Celda> pila;
    int numCeldas;

public:

    //Constructor por defecto
    PilaMaxVD();

    //Constructor de copia
    PilaMaxVD(const PilaMaxVD otraPila);
};


#endif // PilaMaxVD_h