//
// Created by hun46 on 2019. 04. 17..
//

#ifndef THREEMORECLASSES_FARM_H
#define THREEMORECLASSES_FARM_H

#include "Animal.h"
#include <vector>


class Farm {

public:
    Farm(int slots = 10);
    void breed(Animal);
    void slaughter();

private:
    int slots;
    std::vector<Animal> animals;


};


#endif //THREEMORECLASSES_FARM_H
