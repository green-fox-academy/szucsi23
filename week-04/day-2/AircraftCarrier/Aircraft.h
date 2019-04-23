//
// Created by hun46 on 2019. 04. 23..
//

#ifndef AIRCRAFTCARRIER_AIRCRAFT_H
#define AIRCRAFTCARRIER_AIRCRAFT_H

#include <iostream>
#include <sstream>

enum Type {
    F16,
    F35
};

class Aircraft {
public:
    Aircraft(Type type);

    std::string getType();
    std::string getStatus();
    bool isPriority();
    int fight();
    int refill(int);

private:
    Type _type;
    int _ammo;
    int _maxAmmo;
    int _baseDamage;

};


#endif //AIRCRAFTCARRIER_AIRCRAFT_H
