//
// Created by hun46 on 2019. 04. 23..
//

#include "Flower.h"


int Flower::getLimit()
{
    return 5;
}

double Flower::getPercentage()
{
    return 0.75;
}

Flower::Flower(const std::string &colour, Type type, int waterLevel) : Plant(colour, type, waterLevel)
{}
