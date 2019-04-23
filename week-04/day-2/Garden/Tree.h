//
// Created by hun46 on 2019. 04. 23..
//

#ifndef GARDEN_TREE_H
#define GARDEN_TREE_H

#include "Plant.h"

class Tree : public Plant{
public:
    void status() override ;
    void watering(double) override ;
private:
};


#endif //GARDEN_TREE_H
