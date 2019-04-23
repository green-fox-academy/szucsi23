//
// Created by hun46 on 2019. 04. 23..
//

#include "Garden.h"

void Garden::add(Plant* plant)
{
    _plants.insert(_plants.end(), plant);
}

int Garden::statusUpdate()
{
    int thirsty = 0;
    for (int i = 0; i < _plants.size(); ++i) {
        if(_plants.at(i)->status()){
            thirsty++;
        }
    }
    return thirsty;
}

void Garden::watering(double amount)
{
    int thirsty = statusUpdate();
    double amountPerPlant = amount / thirsty;
    for (int i = 0; i < _plants.size(); ++i) {
        if(_plants.at(i)->status()){
            _plants.at(i)->watering(amountPerPlant);
        }
        _plants.at(i)->statusOut();
    }

}
