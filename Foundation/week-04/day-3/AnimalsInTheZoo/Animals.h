//
// Created by hun46 on 2019. 04. 24..
//

#ifndef ANIMALSINTHEZOO_ANIMALS_H
#define ANIMALSINTHEZOO_ANIMALS_H
#include <iostream>

enum Eats {
    HERBIVORE,
    CARNIVORE,
    OMNIVORE
};

class Animals {
public:
    Animals(const std::string &name);

    virtual std::string getname() = 0;
    virtual std::string breed() = 0;
    virtual void escape();
protected:
    std::string _name;
    int _age;
    bool _cuteness;
    Eats _eats;


};


#endif //ANIMALSINTHEZOO_ANIMALS_H
