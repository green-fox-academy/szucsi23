//
// Created by hun46 on 2019. 04. 24..
//

#include "Mammals.h"

std::string Mammals::getname()
{
    return _name;
}

std::string Mammals::breed()
{
    return "pushing out miniature versions of itself";
}

Mammals::Mammals(const std::string &name) : Animals(name)
{}
