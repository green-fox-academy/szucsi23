//
// Created by hun46 on 2019. 04. 23..
//

#include "Person.h"

Person::Person()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
}

Person::Person(std::string name, int age, Gender gender)
{
    _age = age;
    _name = name;
    _gender = gender;
}

void Person::introduce()
{
    std::cout << "Hello, my name is " << _name << " and I'm a " << _age << " years old " << _gender << "." << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment." << std::endl;
}

int Person::getAge() const
{
    return _age;
}

const std::string &Person::getName() const
{
    return _name;
}

std::string Person::getRealGender()
{
    switch(_gender) {
        case MALE: return "male";
        case FEMALE: return "female";
        case APACHEHELICOPTER: return "apache helicopter";
    }
}
