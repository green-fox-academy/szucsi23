//
// Created by hun46 on 2019. 04. 17..
//

#include <string>
#ifndef THREEMORECLASSES_SHARPIE_H
#define THREEMORECLASSES_SHARPIE_H


class Sharpie {
public:
    Sharpie(std::string color, float width);
    void use();

private:
    std::string color;
    float inkAmount = 100;
    float width;
};


#endif //THREEMORECLASSES_SHARPIE_H
