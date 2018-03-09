#include "Escenario.h"
#include "Invisible.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

Invisible::Invisible(string nombre) :Escenario(nombre){
    this->vidas = rand()% 3+1;
}

Invisible::Invisible(){

}

Invisible:: ~Invisible(){
}

int Invisible::  getVidas(){
    return vidas;
}

void Invisible::   setTipoBomba(int tipoBomba){
    this->tipoBomba = tipoBomba;
}

int  Invisible::  getTipoBomba(){
    return tipoBomba;
}