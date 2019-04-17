//
// Created by hun46 on 2019. 04. 17..
//

#include "Station.h"
#include <iostream>

Station::Station(int gasAmount)
{
    this->gasAmount = gasAmount;
}

void Station::fill(Car c)
{
    while(!c.isFull() && (this->gasAmount > 0)){
        c.fill();
        this->gasAmount--;
        std::cout << "Filling car... (" << c.getGasAmount() << "/" << c.getCapacity() << ")" << std::endl;
    }
    std::cout << "Filling done. Remaining gas at station: " << this->gasAmount << std::endl;
}

int Station::getGasAmount() const
{
    return gasAmount;
}

void Station::setGasAmount(int gasAmount)
{
    Station::gasAmount = gasAmount;
}
