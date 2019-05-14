#include <iostream>
#include <cstring>




std::string unique(int[], int);


int main() {
    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int size = sizeof(numbers)/ sizeof(int);

    std::string uniquestr = unique(numbers, size);

    std::cout << unique(numbers, size);


    return 0;
}


std::string unique(int numbers[], int size) {
    int small = 0;
    int temp = 0;
    std::string str = "";

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
        if(numbers[i] != numbers[i+1]) {
            str += std::to_string(numbers[i]);
            str += " ";
        }
    }
    return str;
}