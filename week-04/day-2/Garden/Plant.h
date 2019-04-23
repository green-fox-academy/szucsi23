//
// Created by hun46 on 2019. 04. 23..
//

#ifndef GARDEN_PLANT_H
#define GARDEN_PLANT_H

#include <iostream>

enum Type {
    TREE,
    FLOWER,
    NOTYETDEFINED
};

class Plant {
public:
    Plant();
    Plant(std::string colour, Type type, int waterLevel);

    double getWaterLevel() const;
    const std::string &getColour() const;
    std::string getTypeString() const;

    virtual void status(int);
    virtual void watering(double, double);
private:
    double _waterLevel;
    std::string _colour;
    Type _type;

};


#endif //GARDEN_PLANT_H
