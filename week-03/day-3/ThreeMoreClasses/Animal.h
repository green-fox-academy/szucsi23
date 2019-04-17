//
// Created by hun46 on 2019. 04. 17..
//

#ifndef THREEMORECLASSES_ANIMAL_H
#define THREEMORECLASSES_ANIMAL_H


class Animal {
public:
    Animal(int hunger = 50, int thirst = 50);
    void eat();
    void drink();
    void play();

private:
    int hunger;
    int thirst;

};


#endif //THREEMORECLASSES_ANIMAL_H
