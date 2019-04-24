//
// Created by hun46 on 2019. 04. 24..
//

#include "BassGuitar.h"

BassGuitar::BassGuitar(int x) : StringedInstrument(x, "Bass Guitar")
{

}

std::string BassGuitar::sound()
{
    if (_numberOfStrings == 4) return "Dumm-dumm";
    else if(_numberOfStrings == 5) return "Dumm-dumm-dumm";
    else if(_numberOfStrings < 4) return "sad Dumm";
    else return "confused Dumm";
}
