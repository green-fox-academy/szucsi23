//
// Created by hun46 on 2019. 04. 23..
//

#ifndef GARDEN_GARDEN_H
#define GARDEN_GARDEN_H

#include "Flower.h"
#include "Tree.h"
#include <vector>

class Garden {
public:
    void add(Plant*);
    int statusUpdate();
    void watering(double);

private:
    std::vector<Plant*> _plants;
};


#endif //GARDEN_GARDEN_H
