#include <iostream>
#include <ctime>

#include "dice_set.h"

int main(int argc, char* args[])
{
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6
    std::clock_t start;
    double duration;

    DiceSet diceSet;
    int sixes = 0;

    diceSet.roll();
    for (int i = 0; i < 6; ++i) {
        std::cout << diceSet.getCurrent(i) << " ";
    }
    std::cout << std::endl;

    start = std::clock();
    while(sixes != 6) {
        sixes = 0;
        diceSet.roll();

        for (int i = 0; i < 6; ++i) {
            if(diceSet.getCurrent(i) == 6) sixes++;
        }
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << duration << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cout << diceSet.getCurrent(i) << " ";
    }

    return 0;
}