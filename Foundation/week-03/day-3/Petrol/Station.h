//
// Created by hun46 on 2019. 04. 17..
//
#include "Car.h"

#ifndef PETROL_STATION_H
#define PETROL_STATION_H


class Station {
public:
    Station(int gasAmount = 10000);
    void fill(Car);

    int getGasAmount() const;

    void setGasAmount(int gasAmount);

private:
    int gasAmount;
};

#endif //PETROL_STATION_H
