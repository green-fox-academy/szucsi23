//
// Created by hun46 on 2019. 04. 17..
//

#include "Animal.h"

Animal::Animal(int hunger, int thirst)
{
    this->hunger = hunger;
    this->thirst = thirst;
}

void Animal::eat()
{this->hunger--;}

void Animal::drink()
{this->thirst--;}

void Animal::play()
{this->hunger++;
this->thirst++;}