#include <string>
#include <iostream>
#include "Item.h"
using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H


//Inicio clase
class Jugador:public Item{

    //Atributos
    private:
        string nombre;
        int estado;
        int tipo;


    //metodos publicos
    public:
        //prototipos de metodos
        //constructor
        Jugador();
        Jugador(string,int,int, int, int);

        //metodos accersores / mutadores
        string getNombre();
        void setNombre(string);
        int getEstado();
        void setEstado(int);
        int getTipo();
        void setTipo(int);

    //Destructor
    ~Jugador();


};//Fin de la clase


#endif
