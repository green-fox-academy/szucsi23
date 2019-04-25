//
// Created by hun46 on 2019. 04. 25..
//


#include "apple.h"

std::string getApple()
{
    return "alma";
}

int sum(std::vector<int> applesOnTrees)
{
    int sum = 0;
    for (int i = 0; i < applesOnTrees.size(); ++i) {
        sum += applesOnTrees[i];
    }
    return sum;
}

bool isPalindrom(std::string str) {
    bool itsgood = true;
    std::string swapped = swapper(str);
    int size = str.length();
    for (int i = 0; i < size && itsgood; ++i) {
        if (str[i] != swapped[i]) {
            itsgood = false;
        }
    }
    return itsgood;
}

std::string swapper(std::string str) {
    int size = str.length();
    std::string swapped = "";

    for (int i = 0; i < size; ++i) {
        swapped += str[size - i - 1];

    }

    return swapped;
}