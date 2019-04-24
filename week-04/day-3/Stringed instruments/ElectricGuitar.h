//
// Created by hun46 on 2019. 04. 24..
//

#ifndef STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
#define STRINGED_INSTRUMENTS_ELECTRICGUITAR_H

#include "StringedInstrument.h"

class ElectricGuitar : public StringedInstrument{
public:
    ElectricGuitar(int x = 6);

    std::string sound() override;

protected:
private:

};


#endif //STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
