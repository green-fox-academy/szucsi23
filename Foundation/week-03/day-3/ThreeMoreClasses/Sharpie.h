//
// Created by hun46 on 2019. 04. 17..
//

#include <string>
#ifndef THREEMORECLASSES_SHARPIE_H
#define THREEMORECLASSES_SHARPIE_H


class Sharpie {
public:
    Sharpie(std::string color = "black", float width = 5.0);
    void use();

    float getInkAmount() const;

private:
    std::string color;
    float inkAmount = 100;
    float width;
};


#endif //THREEMORECLASSES_SHARPIE_H
