#include "Bombas.h"
#include <iostream>
#include <string>

using namespace std;

//Cosntructor 1
Bombas::Bombas(int contador){
    this->contador=contador;
}//Fin constructor

//Constructor2
Bombas::Bombas(){

}//Fin constructor sencillo

int Bombas::getContador(){
    return contador;
}

void Bombas:: setContador(int contador){

    this->contador=contador;

}

Bombas::~Bombas(){

    cout<<"La instancia de Bombas fue eliminada";

}
