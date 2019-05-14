//
// Created by hun46 on 2019. 04. 24..
//

#ifndef ANIMALSINTHEZOO_BIRDS_H
#define ANIMALSINTHEZOO_BIRDS_H

#include "Animals.h"

class Birds : public Animals{
public:
    Birds(const std::string &name);

    std::string getname() override;
    std::string breed() override;
private:
    int wingspan;
    bool nesting;
};


#endif //ANIMALSINTHEZOO_BIRDS_H
