//
// Created by hun46 on 2019. 04. 17..
//

#ifndef THREEMORECLASSES_SHARPIESET_H
#define THREEMORECLASSES_SHARPIESET_H

#include <vector>
#include "Sharpie.h"


class SharpieSet {
public:
    void add(Sharpie);
    int countUsable();
    void removeTrash();


private:
    std::vector<Sharpie> set;
};


#endif //THREEMORECLASSES_SHARPIESET_H
