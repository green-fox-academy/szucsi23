//
// Created by hun46 on 2019. 04. 17..
//

#include "Farm.h"

Farm::Farm(int slots)
{
    this->slots = slots;
}

void Farm::breed(Animal a)
{
    if(this->slots > 0){
        this->animals.push_back(a);
        slots--;
    }

}

void Farm::slaughter()
{
    std::vector<Animal>::iterator iter = this->animals.begin();
    std::vector<Animal>::iterator min = iter;
    for (; iter < this->animals.end(); ++iter) {
        if(min->getHunger() > iter->getHunger()) min = iter;
    }
    this->animals.erase(min);
    this->slots++;

}
