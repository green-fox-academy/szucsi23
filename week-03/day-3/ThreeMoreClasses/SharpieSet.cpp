//
// Created by hun46 on 2019. 04. 17..
//

#include "SharpieSet.h"

void SharpieSet::add(Sharpie s)
{
    this->set.push_back(s);
}

int SharpieSet::countUsable()
{
    int counter = 0;
    std::vector<Sharpie>::iterator iterator = this->set.begin();
    for (; iterator < this->set.end(); iterator++) {
        if((iterator->getInkAmount()) > 0) counter++;
    }
    return counter;
}

void SharpieSet::removeTrash()
{
    std::vector<Sharpie>::iterator iterator = this->set.begin();
    for (; iterator < this->set.end(); iterator++) {
        if((iterator->getInkAmount()) == 0) this->set.erase(iterator);
    }
}
