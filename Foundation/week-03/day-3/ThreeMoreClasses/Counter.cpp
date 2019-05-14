//
// Created by hun46 on 2019. 04. 17..
//

#include "Counter.h"

Counter::Counter(int num)
{
    this->num = num;
    this->store = num;
}

void Counter::add()
{
    this->num++;
}

void Counter::add(int theother)
{
    this->num += theother;

}

int Counter::get() const
{
    return num;
}

void Counter::set(int num)
{
    this->num = num;
}

void Counter::reset()
{
    this->num = this->store;
}
