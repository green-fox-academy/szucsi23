//
// Created by hun46 on 2019. 04. 24..
//

#include "Birds.h"

std::string Birds::getname()
{
    return _name;
}

std::string Birds::breed()
{
    return "laying eggs";
}

Birds::Birds(const std::string &name) : Animals(name)
{}
