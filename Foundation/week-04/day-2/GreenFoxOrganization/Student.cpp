//
// Created by hun46 on 2019. 04. 23..
//

#include "Student.h"

Student::Student () : Person()
{
    _previousOrganization = "The School of Life";
    _skippedDays = 0;

}

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization) : Person(name, age, gender)
{
    _previousOrganization = previousOrganization;
    _skippedDays = 0;
}

void Student::introduce()
{
    std::cout << "Hello, my name is " << getName() << " and I'm a " << getAge() << " years old " << getRealGender();
    std::cout << " from " << _previousOrganization << " who skipped " << _skippedDays << " days already." << std::endl;

}

void Student::getGoal()
{
    std::cout << "My goal: Be a junior software developer." << std::endl;
}

void Student::skipDays(int numberOfDays)
{
    _skippedDays += numberOfDays;
}


