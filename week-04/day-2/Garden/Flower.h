//
// Created by hun46 on 2019. 04. 23..
//

#ifndef GARDEN_FLOWER_H
#define GARDEN_FLOWER_H

#include "Plant.h"

class Flower : public Plant{
public:
    Flower(const std::string &colour, Type type, int waterLevel);

    double getPercentage() override;
    int getLimit() override;
private:
};


#endif //GARDEN_FLOWER_H
