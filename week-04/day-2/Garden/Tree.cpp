//
// Created by hun46 on 2019. 04. 23..
//

#include "Tree.h"


double Tree::getPercentage()
{
    return 0.40;
}

int Tree::getLimit()
{
    return 10;
}

Tree::Tree(const std::string &colour, Type type, int waterLevel) : Plant(colour, type, waterLevel)
{}
