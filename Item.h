#include <string>
#include <iostream>

using namespace std;

#ifndef ITEM_H
#define ITEM_H


//Inicio clase
class Item{
    private:
        int x;
        int y;
    public:
        Item();
        Item(int,int);
        int getX();
        void setX(int);
        int getY();
        void setY(int);
	virtual string toString();
    ~Item();


};
#endif
