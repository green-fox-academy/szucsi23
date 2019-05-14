//
// Created by hun46 on 2019. 04. 24..
//

#include "Violin.h"

Violin::Violin(int x) : StringedInstrument(x, "Violin")
{

}

std::string Violin::sound()
{
    if (_numberOfStrings == 4) return "Screech";
    else if(_numberOfStrings == 5) return "Screech-Screech";
    else if(_numberOfStrings < 4) return "sad Screech";
    else return "confused Screech";
}
