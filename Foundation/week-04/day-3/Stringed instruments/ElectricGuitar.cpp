//
// Created by hun46 on 2019. 04. 24..
//

#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar(int x) : StringedInstrument(x, "Electric Guitar")
{

}

std::string ElectricGuitar::sound()
{
    if (_numberOfStrings == 6) return "Twang";
    else if(_numberOfStrings == 7) return "Twangg";
    else if(_numberOfStrings < 6) return "sad Twang";
    else return "confused Twang";
}
