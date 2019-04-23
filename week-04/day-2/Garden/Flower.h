//
// Created by hun46 on 2019. 04. 23..
//

#ifndef GARDEN_FLOWER_H
#define GARDEN_FLOWER_H

#include "Plant.h"

class Flower : public Plant{
public:
    void status() override ;
    void watering(double) override ;
private:
};


#endif //GARDEN_FLOWER_H
