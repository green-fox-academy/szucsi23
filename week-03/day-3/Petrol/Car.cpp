//
// Created by hun46 on 2019. 04. 17..
//

#include "Car.h"

Car::Car(int gasAmount, int capacity)
{
    this->gasAmount = gasAmount;
    this->capacity = capacity;
}

int Car::getGasAmount() const
{
    return gasAmount;
}

void Car::setGasAmount(int gasAmount)
{
    Car::gasAmount = gasAmount;
}

bool Car::isFull()
{
    if(this->capacity == this->gasAmount) {
        return true;
    } else return false;
}

void Car::fill()
{
this->gasAmount++;
}

int Car::getCapacity() const
{
    return capacity;
}
