//
// Created by hun46 on 2019. 04. 18..
//

#ifndef PIRATESOFTHEC___ARMADA_H
#define PIRATESOFTHEC___ARMADA_H

#include "Ship.h"
#include <vector>
#include <time.h>
#include <iostream>


class Armada {
public:
    void formAFleet();
    bool war(Armada);
private:
    std::vector<Ship> fleet;
};


#endif //PIRATESOFTHEC___ARMADA_H
