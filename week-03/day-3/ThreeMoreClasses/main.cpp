#include <iostream>
#include "Animal.h"
#include "Sharpie.h"
#include "Counter.h"
#include "SharpieSet.h"
#include "Farm.h"

void checkValue(const std::string& name, int expected, int actual)
{
    if(expected != actual) {
        std::cout << name << "Failed! Expected: " << expected << " Actual: " << actual << std::endl;
    }
    else {
        std::cout << name << "Passed!" << std::endl;
    }
}

int main(int argc, char* args[])
{
    Counter c;
    checkValue("getZero", 0, c.get());

    c.add(5);
    checkValue("addMore", 5, c.get());

    c.add();
    checkValue("addOne", 6, c.get());

    c.reset();
    checkValue("getZero2", 0, c.get());

    Counter c2(7);
    checkValue("getInit", 7, c2.get());

    c2.reset();
    checkValue("reset", 7, c2.get());

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    Sharpie s1;
    Sharpie s2("blue", 4.0);
    Sharpie s3("green", 1.0);
    Sharpie s4("red", 2.3);

    for (int i = 0; i < 100; ++i) {
        s1.use();
    }
    for (int i = 0; i < 50; ++i) {
        s2.use();
    }

    SharpieSet mySet;
    mySet.add(s1);
    mySet.add(s2);
    mySet.add(s3);
    mySet.add(s4);

    int count = mySet.countUsable();
    mySet.removeTrash();
    std::cout << count;

    Animal tiger;
    Animal cat(20, 1);
    Animal parrot(2, 3);
    Animal axolotl(100, 100);

    Farm myFarm;
    myFarm.breed(tiger);
    myFarm.breed(cat);
    myFarm.breed(parrot);
    myFarm.breed(axolotl);

    myFarm.slaughter();


















    return 0;
}