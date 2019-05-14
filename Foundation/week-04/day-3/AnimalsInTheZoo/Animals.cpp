//
// Created by hun46 on 2019. 04. 24..
//

#include "Animals.h"

Animals::Animals(const std::string &name) : _name(name)
{}

void Animals::escape()
{
 std::cout << "They escapes... You are fired!" << std::endl;
}
