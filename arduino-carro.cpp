#include "arduino.h"
#include "arduino-carro.h"

Carro::Carro(){
    pinMode(ruedaIzquierdaAdelante, OUTPUT);
    pinMode(ruedaDerechaAdelante, OUTPUT);
    pinMode(ruedaIzquierdaRetroceso, OUTPUT);
    pinMode(ruedaDerechaRetroceso, OUTPUT);

}


void Carro::mover(int izquierda, int derecha){
    izquierda = constrain(izquierda,-10,10);
    derecha = constrain(derecha,-10,10);

    digitalWrite(ruedaIzquierdaAdelante, izquierda < 0 ? 0 : (izquierda > 0 ? 1 : 0) );
    digitalWrite(ruedaIzquierdaRetroceso, izquierda < 0 ? 0 : (izquierda > 0 ? 0 : 0));

    digitalWrite(ruedaDerechaAdelante, derecha < 0 ? 0 : (derecha > 0 ? 1 : 0));
    digitalWrite(ruedaDerechaRetroceso, derecha < 0 ? 1 : (derecha > 0 ? 0 : 0));

}

void Carro::girar(int grados){
    int tiempo = 500;

    mover(0,0);
    delay(100);

    if(grados > 0){
        mover(10,-10);
    }else if(grados < 0){
        mover(-10,10)
    }

    delay(tiempo);

    mover(0,0);
    delay(100);
}