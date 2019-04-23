//
// Created by hun46 on 2019. 04. 23..
//

#include "Plant.h"

Plant::Plant()
{
    _colour = "black";
    _type = NOTYETDEFINED;
    _waterLevel = 0;
}

Plant::Plant(std::string colour, Type type, int waterLevel)
{
    _colour = colour;
    _type = type;
    _waterLevel = waterLevel;
}

double Plant::getWaterLevel() const
{
    return _waterLevel;
}

const std::string &Plant::getColour() const
{
    return _colour;
}

std::string Plant::getTypeString() const
{
    switch(_type) {
        case TREE: return "Tree";
        case FLOWER: return "Flower";
        case NOTYETDEFINED: return "Not specified";
    }
}

void Plant::watering(double percentage, double amount)
{
    _waterLevel += (amount * percentage);
}

void Plant::status(int margin)
{
    if(getWaterLevel() < margin) {
        std::cout << "The " << _colour << " " << getTypeString() << " needs water." << std::endl;
    } else {
        std::cout << "The " << _colour << " " << getTypeString() << " doesn't need water." << std::endl;
    }
}
