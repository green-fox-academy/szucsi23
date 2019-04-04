#include <iostream>
#include <string>

int unique (int[], int[], int);

int main() {
    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int size = sizeof(numbers)/ sizeof(int);
    int temp_arr[size];
    int count = 0;

    count = unique(numbers, temp_arr, size);

    int unique_arr[count];

    for (int i = 0; i < count; ++i) {
        unique_arr[i]=temp_arr[i];
    }

    for (int i = 0; i < count; ++i) {
        std::cout << unique_arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

int unique(int numbers[], int temp_arr[], int size){
    int count = 0;


    for (int i = 0; i < size; ++i) {
        int temp = numbers[i];
        bool mehet = true;

        for (int j = i+1; j < size; ++j) {
            if (numbers[j] != temp && mehet) {
                count++;
                temp_arr[i]=numbers[i];
                mehet = false;
            }
        }
    }

    return count;
}