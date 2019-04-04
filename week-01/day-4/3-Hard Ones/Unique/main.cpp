#include <iostream>
#include <string>

int unique (int[], int);
int unique2 (int[], int);

int main() {
    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int size = sizeof(numbers)/ sizeof(int);

    int count = 0;

    count = unique(numbers, size);

    
    return 0;
}



int unique (int numbers[], int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(numbers[i]==numbers[j]);

        }
    }

}



int unique2(int numbers[], int size){
    int count = 0;
    int organized = 0;
    int organized_arr[size];
    int temp_arr[size];

    for (int i = 0; i < size; ++i) {
        organized_arr[i] = numbers [i];
    }


    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (organized_arr[i] >= organized_arr[j]) {
                organized = organized_arr[i];
                organized_arr[i] = organized_arr[j];
                organized_arr[j] = organized;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        if(organized_arr[i]==organized_arr[i+1]) {
            temp_arr[count] = organized_arr[i];
            i++;
            count++;
        }
    }

    for (int i = 0; i < count; ++i) {
        std::cout << temp_arr[i] << " ";
    }
    return count;
}