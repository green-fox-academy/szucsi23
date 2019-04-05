#include <iostream>
#include <cstring>
#include <stdlib.h>

std::string unique(int[], int);


int main() {
    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int size = sizeof(numbers) / sizeof(int);

    std::string tempstr = unique(numbers, size);
    int tempsize = tempstr.length();

    int uniquesize = 0;
    std::string temptempstr = "";

    std::cout << tempstr << std::endl;

    bool gotit = false;
    for (int i = 0; i < tempsize; ++i) {
        if (tempstr[i+1] == ' ' && gotit == false) {
            for (int j = 0; j <= i; ++j) {
                temptempstr += tempstr[j];
                gotit = true;
            }
        }
    }

    int realsize = stoi(temptempstr);

    std::cout << realsize << std::endl;

    int finallydone[realsize];

    temptempstr = "";
    int count = 0;

    for (int i = 0; i < tempsize; ++i) {
        if (tempstr[i - 1] == ' ') {
            int j = i;
            while (tempstr[j + 1] != ' ') j++;
            for (int k = i; k <= j; ++k) {
                temptempstr += tempstr[k];

            }
            finallydone[count] = stoi(temptempstr);
            temptempstr = "";
            count++;
        }
    }

    for (int i = 0; i < realsize; ++i) {
        std::cout << finallydone[i] << " ";
    }

    return 0;
}


std::string unique(int numbers[], int size) {
    int small = 0;
    int temp = 0;
    std::string tempstr = "";
    std::string str;
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] >= numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        if (numbers[i] != numbers[i + 1]) {
            tempstr += " ";
            tempstr += std::to_string(numbers[i]);
            count++;
        }
    }
    tempstr += " ";
    str = std::to_string(count);
    str += tempstr;
    return str;
}