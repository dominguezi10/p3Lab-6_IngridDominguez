#include <string>
#include <iostream>
#include "Bombas.h"

using namespace std;

#ifndef NORMAL_H
#define NORMAL_H


//Inicio clase
class Normal: public Bombas{

    //Atributos
    private:
        int alcance;


    //metodos publicos
    public:
        //prototipos de metodos
        //constructor
        Normal();
        Normal(int);

        //metodos accersores / mutadores
        int getAlcance();
        void setAlcance(int);

    //Destructor
    ~Normal();


};//Fin de la clase


#endif
