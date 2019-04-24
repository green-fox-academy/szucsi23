//
// Created by hun46 on 2019. 04. 24..
//

#ifndef ANIMALSINTHEZOO_REPTILES_H
#define ANIMALSINTHEZOO_REPTILES_H


#include "Animals.h"

class Reptiles : public Animals{
public:
    Reptiles(const std::string &name);

    std::string getname() override;
    std::string breed() override;
private:
    int weight;
    bool swim;
};

#endif //ANIMALSINTHEZOO_REPTILES_H
