//
// Created by hun46 on 2019. 04. 17..
//

#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width)
{
    this->color = color;
    this->width = width;
}

void Sharpie::use()
{
    this->inkAmount--;
}
