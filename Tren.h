#include <string>
#include <iostream>
#include "Escenario.h"
#include <vector>
using namespace std;

#ifndef TREN_H
#define TREN_H


//Inicio clase
class Tren: public Escenario{
    private:
        vector<int> posiciones;
        int dondeEsta;

    public:
        Tren(string);
        int getDondeEsta();
        void setDondeEsta(int);

        ~Tren();

};
#endif