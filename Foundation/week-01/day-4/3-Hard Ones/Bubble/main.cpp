#include <iostream>
#include <string>

//  Create a function that takes a list of numbers as parameter
//  Don't forget you have to pass the size of the list as a parameter as well
//  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
//  Make a second boolean parameter, if it's `true` sort that list descending

void sort (int [], int, bool);

int main() {


    int numbers[] = {1, 2, 6, 5, 4, 3, 9, 8, 7, 2};
    int size = sizeof(numbers)/ sizeof(int);
    bool desc = false;

    sort(numbers, size, desc);

    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}

void sort (int numbers[], int size, bool desc){
    int temp = 0;
    if(!desc){
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (numbers[i] >= numbers[j]) {
                    temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (numbers[i] <= numbers[j]) {
                    temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }
    }
}