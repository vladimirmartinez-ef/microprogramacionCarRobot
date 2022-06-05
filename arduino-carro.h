#ifndef arduino-carro_h
#define arduino-carro_h
#include "arduino.h"

class Carro(
    byte ruedaIzquierdaAdelante = 5;
    byte ruedaIzquierdaRetroceso = 4;
    byte ruedaDerechaAdelante = 3;
    byte ruedaDerechaRetroceso = 2;

    Carro();

    void alto();
    void mover(int izquierda, int derecha);
    void girar(int grados, int tiempo);
)

#endif
