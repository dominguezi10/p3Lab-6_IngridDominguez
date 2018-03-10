#include <iostream>
using namespace std;
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <vector>
#include <sstream>

#include "Escenario.h"
#include "Item.h"
#include "Jugador.h"
#include "Tren.h"
#include "Invisible.h"

void salir();
int menu();
void movimiento();
int kbhit(void);

Jugador* crearJugador(int);
int tipoBomba();
void movimientoInvisible();
void movimientoTren();

int main(void){
    Escenario* escenario;
    Jugador* jugador;
    int OpcionJuego;
    string nombreE;
    
    while (OpcionJuego != 3) {
        erase();
        OpcionJuego = menu();
        switch (OpcionJuego)
        {
        case 1: {
            erase();
            move(0, 20);
            printw("Escenario 1 Invisible");
            move(2,1);
            nombreE = "Invisible";
            //escenario->setNombre(nombreE);
            jugador = crearJugador(1);

            escenario = new Invisible(nombreE);

            int opcion ;
            opcion = tipoBomba();

            movimientoInvisible();
            refresh();
            usleep(1000000);
            
            refresh();
            break;
        }
        case 2: {
            erase();
            move(0, 20);
            printw("Opcion 2 Tren");
            nombreE = "Tren";
            move(2,1);
            nombreE = "Invisible";
            //escenario->setNombre(nombreE);
            jugador = crearJugador(2);

            escenario = new Tren(nombreE);
            movimientoTren();
            refresh();
            usleep(1000000);
            //movimiento();
            break;
        }
        case 3:{
            salir();
        }
        }
    }

}

int menu(){
    initscr();
    erase();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 6));
    if (has_colors()) {
        start_color();
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        //attron(COLOR_PAIR(1));
        move(1, 5);
        printw("Bombermang !!");
        //attroff(COLOR_PAIR(1));
        
        attron(COLOR_PAIR(2));
        move(2, 1);
        printw("1) Escenario Invisible\n");
        move(3, 1);
        printw("2) El Tren \n");
        move(4, 1);
        printw("3) Salir \n");
        attroff(COLOR_PAIR(2));
    }
    int enX = 0;
    int enY = 2;
    int tecla;
    move(enY, enX);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (enY == 2)
            {
                return 1;
            }
            if (enY == 3)
            {
                return 2;
            }
            if (enY == 4)
            {
                return 3;
            }
            if (enY == 5)
            {
                return 4;
            }
        }
        else
        {
            //printw("%i",tecla);
            if (tecla == 65 && enY > 2)
            {
                //printw(" arriba");
                enY = enY - 1;
                move(enY, enX);
            }
            else if (tecla == 66 && enY <= 4)
            {
                //printw(" abajo");
                enY = enY + 1;
                move(enY, enX);
            }
            else
            {
                //No hara nada
            }
        }
        refresh();
    }
    echo();
    return 0;
}

Jugador* crearJugador(int tipo){
    erase();
    char* nombre = new char[50];
    move(0,5);
    printw("---- Crear Jugador -----");
    move(1,0);
    echo();
    printw("Ingresa el nombre del jugador: ");
    scanw("%s", nombre);
    stringstream eso;
    eso << nombre; 
    string nombreJ;

    getline(eso, nombreJ);
    refresh();

    Jugador* jugador = new Jugador(nombreJ, 1 ,tipo, 0, 0);
    return jugador;
}

int tipoBomba(){
    char este[10];
    move(3,0);
    printw("Opcion de nomba: ");
    move(4,0);
    printw("1.- Normal");
    move(5,0);
    printw("2.- Espina ");
    move(6,0);
    printw("4.- Forma V ");
    scanw("%s", este);

    move(7,0);
    printw("%s", este);

    int opcion;
    opcion= atoi(este);
    return opcion;
}

void salir()
{
    int x, y;
    getmaxyx(stdscr, y, x);
    erase();
    if (has_colors)
    {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(y / 2, (x / 2 - 6));
        printw("Saliendo del Juego");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        attroff(COLOR_PAIR(1));
    }
    endwin();
    exit(0);
}

void movimientoInvisible(){
    erase();
    char ser = '*';
    int x, y;
    int enX;
    int enY;
    getmaxyx(stdscr, y, x);
    
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();
    move(0,0);
    printw("A JUGAR...... (MUEVETE!!)");
    refresh();
    int direccion = 3;
    enX = 0;
    enY = 2;
    curs_set(0);
    erase();
    int tecla;
    tecla = getch();
    while (true)
    {
        /*for(int i= 2; i<13; i++){
            for(int j=0; j<13; i++ ){
                if(i == 5){
                    move(i, j);
                    printw("+");
                    refresh();   
                }
            }
        }*/
        if (kbhit())
        {
            tecla = getch();
            //ARRIBA
            if (tecla == 119)
            {
                direccion = 1;
            }
            //IZQUIERDA
            if (tecla == 97)
            {
                direccion = 2;
            }
            //DERECHA
            if (tecla == 100)
            {
                direccion = 3;
            }
            //ABAJO
            if (tecla == 115)
            {
                direccion = 4;
            }

            if(tecla == 10){
                move(enY, enX);
                printw("O");
                refresh();
            }
        }
        if ((enX > -1 && enY > 1) && (enX < 13 && enY < 11))
        {
            move(enY, enX);
            printw("*");
            refresh();
            usleep(1000000 / 4);
            if (direccion == 1)
            {
                enY = enY - 1;
                move(enY + 1, enX);
                printw(" ");
            }
            if (direccion == 2)
            {
                enX = enX - 1;
                move(enY, enX + 1);
                printw(" ");
            }
            if (direccion == 3)
            {
                enX = enX + 1;
                move(enY, enX - 1);
                printw(" ");
            }
            if (direccion == 4)
            {
                enY = enY + 1;
                move(enY - 1, enX);
                printw(" ");
            }
        }
        else
        {
            break;
        }
    }
    move(y / 2, (x / 2 - 4));
    printw("Perdió!!");
    refresh();
    usleep(1000000 / 2);
    curs_set(1);
}


void movimientoTren(){
    erase();
    char ser = '*';
    int x, y;
    int enX;
    int enY;
    getmaxyx(stdscr, y, x);
    
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();
    move(0,0);
    printw("A JUGAR...... (MUEVETE!!)");
    refresh();
    int direccion = 3;
    enX = 0;
    enY = 2;
    curs_set(0);
    erase();
    int tecla;
    tecla = getch();
    while (true)
    {
        
        if (kbhit())
        {
            tecla = getch();
            //ARRIBA
            if (tecla == 119)
            {
                direccion = 1;
            }
            //IZQUIERDA
            if (tecla == 97)
            {
                direccion = 2;
            }
            //DERECHA
            if (tecla == 100)
            {
                direccion = 3;
            }
            //ABAJO
            if (tecla == 115)
            {
                direccion = 4;
            }
            
        }
        if ((enX > -1 && enY > 1) && (enX < 13 && enY < 11))
        {
            move(enY, enX);
            printw("*");
            refresh();
            usleep(1000000 / 4);
            if (direccion == 1)
            {
                enY = enY - 1;
                move(enY + 1, enX);
                printw(" ");
            }
            if (direccion == 2)
            {
                enX = enX - 1;
                move(enY, enX + 1);
                printw(" ");
            }
            if (direccion == 3)
            {
                enX = enX + 1;
                move(enY, enX - 1);
                printw(" ");
            }
            if (direccion == 4)
            {
                enY = enY + 1;
                move(enY - 1, enX);
                printw(" ");
            }
        }
        else
        {
            break;
        }
    }
    move(y / 2, (x / 2 - 4));
    printw("Perdió!!");
    refresh();
    usleep(1000000 / 2);
    curs_set(1);
}



void movimiento()
{
    erase();
    //vector <char> ser={'*','*','*'};
    char ser = '*';
    int x, y;
    int enX = 1;
    int enY = 1;
    getmaxyx(stdscr, y, x);
    move(y / 2, x / 2 - 18);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printw("Presione ENTER para iniciar el juego.");
    move(y / 2 + 1, x / 2 - 29);
    printw("*Las teclas sólo funcionarán sin no está activo BLOQ MAYUS*");
    refresh();
    attroff(COLOR_PAIR(1));
    int tecla;
    tecla = getch();
    while (tecla != 10)
    {
        tecla = getch();
    }
    int direccion = 3;
    enX = x / 2;
    enY = y / 2;
    curs_set(0);
    erase();
    while (true)
    {
        if (kbhit())
        {
            tecla = getch();
            //ARRIBA
            if (tecla == 119)
            {
                direccion = 1;
            }
            //IZQUIERDA
            if (tecla == 97)
            {
                direccion = 2;
            }
            //DERECHA
            if (tecla == 100)
            {
                direccion = 3;
            }
            //ABAJO
            if (tecla == 115)
            {
                direccion = 4;
            }
        }
        if ((enX > 0 && enY > 0) && (enX < x && enY < y))
        {
            move(enY, enX);
            printw("*");
            refresh();
            usleep(1000000 / 4);
            if (direccion == 1)
            {
                enY = enY - 1;
                move(enY + 1, enX);
                printw(" ");
            }
            if (direccion == 2)
            {
                enX = enX - 1;
                move(enY, enX + 1);
                printw(" ");
            }
            if (direccion == 3)
            {
                enX = enX + 1;
                move(enY, enX - 1);
                printw(" ");
            }
            if (direccion == 4)
            {
                enY = enY + 1;
                move(enY - 1, enX);
                printw(" ");
            }
        }
        else
        {
            break;
        }
    }
    move(y / 2, (x / 2 - 4));
    printw("Perdió!!");
    refresh();
    usleep(1000000 / 2);
    curs_set(1);
}

int kbhit(void)
{
    struct timeval timeout;
    fd_set readfds;
    int how;

    /* look only at stdin (fd = 0) */
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    /* poll: return immediately */
    timeout.tv_sec = 0L;
    timeout.tv_usec = 0L;

    how = select(1, &readfds, (fd_set *)NULL, (fd_set *)NULL, &timeout);
    /* Change "&timeout" above to "(struct timeval *)0"       ^^^^^^^^
         * if you want to wait until a key is hit
         */

    if ((how > 0) && FD_ISSET(0, &readfds))
        return 1;
    else
        return 0;
}