#include <string>
#include <iostream>
#include "Escenario.h"
using namespace std;

#ifndef INVISIBLE_H
#define INVISIBLE_H


//Inicio clase
class Invisible: public Escenario{
    private:
        int vidas;
        int tipoBomba;

    public:
        Invisible();
        Invisible(string);
        int getVidas();
        void setTipoBomba(int);
        int getTipoBomba();

        ~Invisible();

};
#endif
