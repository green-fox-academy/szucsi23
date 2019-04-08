#include <iostream>

int finder (int[], int, int);

int main() {

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    int numbers [5];
    int size = sizeof(numbers)/ sizeof(int);

    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }
    for (int i = 0; i < size; ++i) {
        std::cout << &numbers[i] << " ";
    }

    std::cout << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    //I'm using the previous array.

    int *numbersptr = numbers;
    for (int i = 0; i < size; ++i) {
        std::cout << *numbersptr << " ";
        numbersptr++;
    }
    std::cout << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    int findThis = 3;
    int index = finder(numbers, size, findThis);

    std::cout << index << std::endl;


    return 0;
}

int finder(int numbers[], int size, int find)
{
    for (int i = 0; i < size; ++i) {
        if(find == numbers[i]) {
            return i;
        }
    }
    return -1;
}