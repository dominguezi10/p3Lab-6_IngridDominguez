#include "Jugador.h"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

//Cosntructor 1
Jugador::Jugador(string nombre,int estado,int tipo, int  x, int y):Item(x, y){
    this->nombre=nombre;
    this->estado=estado;
    this->tipo=tipo;
}//Fin constructor

//Constructor2
Jugador::Jugador(){

}//Fin constructor sencillo

string Jugador::getNombre(){
    return nombre;
}

void Jugador:: setNombre(string nombre){

    this->nombre=nombre;

}

int Jugador::getEstado(){
    return estado;
}

void Jugador:: setEstado(int estado){

    this->estado=estado;

}

int Jugador::getTipo(){
    return tipo;
}

void Jugador:: setTipo(int tipo){

    this->tipo=tipo;

}

Jugador::~Jugador(){

    cout<<"La instancia de Jugador fue eliminada";

}
