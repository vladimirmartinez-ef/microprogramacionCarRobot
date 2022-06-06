#ifndef ArduinoCarro_h
#define ArduinoCarro_h


class Carro{
    
public:    
    const int ruedaIzquierdaAdelante = 5;
    const int ruedaIzquierdaRetroceso = 4;
    const int ruedaDerechaAdelante = 3;
    const int ruedaDerechaRetroceso = 2;
    Carro(/* args*/);
    void mover(int izquierda, int derecha);
    void girar(int grados, int tiempo);
};

#endif
