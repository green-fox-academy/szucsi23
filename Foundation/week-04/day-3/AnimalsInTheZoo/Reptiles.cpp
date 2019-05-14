//
// Created by hun46 on 2019. 04. 24..
//

#include "Reptiles.h"

std::string Reptiles::getname()
{
    return _name;
}

std::string Reptiles::breed()
{
    return "laying eggs";
}

Reptiles::Reptiles(const std::string &name) : Animals(name)
{}

