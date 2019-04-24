//
// Created by hun46 on 2019. 04. 24..
//

#ifndef STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
#define STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H

#include "Instrument.h"

class StringedInstrument : public Instrument{
public:
    StringedInstrument(int strings);
    virtual std::string sound() = 0;
    virtual void play();
protected:
    int _numberOfStrings;
private:
};


#endif //STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
