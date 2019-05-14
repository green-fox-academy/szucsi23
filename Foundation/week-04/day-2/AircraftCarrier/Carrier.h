//
// Created by hun46 on 2019. 04. 23..
//

#ifndef AIRCRAFTCARRIER_CARRIER_H
#define AIRCRAFTCARRIER_CARRIER_H

#include "Aircraft.h"
#include <vector>

class Carrier {
public:
    Carrier(int health = 100, int storage = 100);

    int getHealth() const;
    void setHealth(int health);

    void add(Aircraft plane);
    void fill();
    void fight(Carrier ship);
    std::string getStatus();
private:
    int _health;
    int _storage;
    std::vector<Aircraft> _aircrafts;
};


#endif //AIRCRAFTCARRIER_CARRIER_H
