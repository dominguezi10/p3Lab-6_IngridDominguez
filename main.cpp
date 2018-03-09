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
            jugador = crearJugador(1);

            escenario = new Tren(nombreE);
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
        printw("2) Escenario Invisible:\n");
        move(3, 1);
        printw("2) Intento de Snake \n");
        move(4, 1);
        printw("3) Salir \n");
        attroff(COLOR_PAIR(2));
    }
    int cx = 0;
    int cy = 2;
    int tecla;
    move(cy, cx);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (cy == 2)
            {
                return 1;
            }
            if (cy == 3)
            {
                return 2;
            }
            if (cy == 4)
            {
                return 3;
            }
            if (cy == 5)
            {
                return 4;
            }
        }
        else
        {
            //printw("%i",tecla);
            if (tecla == 65 && cy > 2)
            {
                //printw(" arriba");
                cy = cy - 1;
                move(cy, cx);
            }
            else if (tecla == 66 && cy <= 4)
            {
                //printw(" abajo");
                cy = cy + 1;
                move(cy, cx);
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

    Jugador* jugador = new Jugador(nombreJ, 1 ,tipo);
    return jugador;
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
        printw("Saliendo");
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

void movimiento()
{
    erase();
    //vector <char> ser={'*','*','*'};
    char ser = '*';
    int x, y;
    int cx = 1;
    int cy = 1;
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
    cx = x / 2;
    cy = y / 2;
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
        if ((cx > 0 && cy > 0) && (cx < x && cy < y))
        {
            move(cy, cx);
            printw("*");
            refresh();
            usleep(1000000 / 4);
            if (direccion == 1)
            {
                cy = cy - 1;
                move(cy + 1, cx);
                printw(" ");
            }
            if (direccion == 2)
            {
                cx = cx - 1;
                move(cy, cx + 1);
                printw(" ");
            }
            if (direccion == 3)
            {
                cx = cx + 1;
                move(cy, cx - 1);
                printw(" ");
            }
            if (direccion == 4)
            {
                cy = cy + 1;
                move(cy - 1, cx);
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