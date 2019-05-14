//
// Created by hun46 on 2019. 04. 24..
//

#include "StringedInstrument.h"

void StringedInstrument::play()
{
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument, that goes " << sound() << std::endl;
}

StringedInstrument::StringedInstrument(int strings, std::string name)
{
    _numberOfStrings = strings;
    _name = name;
}
