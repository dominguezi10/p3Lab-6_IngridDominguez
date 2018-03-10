main: main.o Escenario.o Item.o Jugador.o Tren.o Invisible.o Bombas.o Normal.o Espina.o V.o
	g++ main.o Escenario.o Item.o Jugador.o Invisible.o Tren.o Bombas.o Normal.o Espina.o V.o  -o main -lncurses


main.o: main.cpp Escenario.h Item.h Jugador.h Tren.h Invisible.h Tren.h
	g++ -c main.cpp

Escenario.o: Escenario.h Escenario.cpp
	g++ -c Escenario.cpp

Item.o: Item.h Item.cpp
	g++ -c Item.cpp 

Jugador.o: Jugador.h Jugador.cpp Item.h
	g++ -c Jugador.cpp

Tren.o: Tren.h Tren.cpp Escenario.h
	g++ -c Tren.cpp

Bombas.o: Bombas.cpp Bombas.h 
	g++ -c Bombas.cpp

Normal.o: Normal.h Normal.cpp Bombas.cpp Bombas.h
	g++ -c Normal.cpp

Espina.o: Espina.h Espina.cpp Bombas.cpp Bombas.h
	g++ -c Espina.cpp

V.o: V.h V.cpp Bombas.cpp Bombas.h
	g++ -c V.cpp

Invisible.o: Invisible.h Invisible.cpp Escenario.h
	g++ -c Invisible.cpp




