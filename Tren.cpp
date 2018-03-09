#include "Escenario.h"
#include "Tren.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

Tren::Tren(string nombre) :Escenario(nombre){
    this->dondeEsta = 1;
}

int Tren::  getDondeEsta(){
    return dondeEsta;
}

void Tren:: setDondeEsta(int dondeEsta){
    this->dondeEsta = dondeEsta;
}


Tren:: ~Tren(){
}