//
// Created by hun46 on 2019. 04. 23..
//

#ifndef GREENFOXORGANIZATION_PERSON_H
#define GREENFOXORGANIZATION_PERSON_H

#include <iostream>

enum Gender {
    MALE,
    FEMALE,
    APACHEHELICOPTER
};


class Person {
public:
    Person();
    Person(std::string name, int age, Gender gender);

    int getAge() const;

    const std::string &getName() const;

    Gender getGender() const;

    virtual void introduce();
    virtual void getGoal();


private:
    int _age;
    std::string _name;
    Gender _gender;


};


#endif //GREENFOXORGANIZATION_PERSON_H
