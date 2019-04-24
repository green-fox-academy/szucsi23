//
// Created by hun46 on 2019. 04. 24..
//

#ifndef ANIMALSINTHEZOO_MAMMALS_H
#define ANIMALSINTHEZOO_MAMMALS_H


#include "Animals.h"

class Mammals : public Animals{
public:
    Mammals(const std::string &name);

    std::string getname() override;
    std::string breed() override;
private:
    int numberOfBabies;
    std::string colourOfFur;
};


#endif //ANIMALSINTHEZOO_MAMMALS_H
