#include "Normal.h"
#include <iostream>
#include <string>

using namespace std;

Normal::Normal(int alcance)
{
    this->alcance = alcance;
}
Normal::Normal()
{
}

int Normal::getAlcance()
{
    return alcance;
}

void Normal::setAlcance(int alcance)
{
    this->alcance = alcance;
}

Normal::~Normal()
{
}


