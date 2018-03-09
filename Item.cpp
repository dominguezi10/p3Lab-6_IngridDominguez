
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item(int x, int y)
{
    this->x = x;
    this->y = y;
}

Item::Item()
{
}

int Item::getX()
{
    return x;
}

void Item::setX(int x)
{

    this->x = x;
}

int Item::getY()
{
    return y;
}

void Item::setY(int y)
{

    this->y = y;
}

Item::~Item()
{
}

string Item::toString()
{
}
