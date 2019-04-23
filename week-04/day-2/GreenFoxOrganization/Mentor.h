//
// Created by hun46 on 2019. 04. 23..
//

#ifndef GREENFOXORGANIZATION_MENTOR_H
#define GREENFOXORGANIZATION_MENTOR_H

#include "Person.h"

enum Level {
    JUNIOR,
    INTERMIDIATE,
    SENIOR
};

class Mentor : public Person{
public:
    Mentor();
    Mentor(std::string name, int age, Gender gender, Level level);

    std::string getRealLevel();

    void getGoal() override;
    void introduce() override;


private:
    Level _level;


};


#endif //GREENFOXORGANIZATION_MENTOR_H
