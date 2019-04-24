//
// Created by hun46 on 2019. 04. 24..
//

#ifndef STRINGED_INSTRUMENTS_INSTRUMENT_H
#define STRINGED_INSTRUMENTS_INSTRUMENT_H

#include <iostream>


class Instrument {
public:
    virtual void play() = 0;
protected:
    std::string _name;
};


#endif //STRINGED_INSTRUMENTS_INSTRUMENT_H
