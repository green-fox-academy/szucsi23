#include <iostream>
#include "Station.h"
#include "Car.h"

int main()
{

    Car bmw(10, 30);
    Car suzuki(20, 40);
    Car vw(12, 54);
    Station station;

    station.fill(bmw);
    std::cout << std::endl;
    station.fill(suzuki);
    std::cout << std::endl;
    station.fill(vw);


    return 0;
}