//
// Created by hun46 on 2019. 04. 18..
//

#include "Armada.h"

void Armada::formAFleet()
{
    for (int i = 0; i < (rand() % 27) + 3; i++) {
        Ship temp;
        temp.fillship();
        this->fleet.push_back(temp);
    }
}

bool Armada::war(Armada other)
{
    std::vector<Ship>::iterator us = this->fleet.begin();
    std::vector<Ship>::iterator them = other.fleet.begin();

    while (true) {
        if (us->battle(*them)) {
            them++;
        } else {
            us++;
        }
        if (us == this->fleet.end()) {
            return false;
        } else if (them == other.fleet.end()) {
            return true;
        }
    }
}
