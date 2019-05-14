#include <iostream>

int main() {

    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    std::cout << "How big should this array be?" << std::endl;
    int size = 0;
    std::cin >> size;

    int numbers [size];
    int max = 0;
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
        if(numbers[i] > max) {
            max = numbers [i];
        }
    }

    std::cout << max << std::endl;








    return 0;
}