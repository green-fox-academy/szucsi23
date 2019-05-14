#include <iostream>

int *maxsearch(int[], int);

int main() {

    std::cout << "How big should this array be?" << std::endl;
    int size = 0;
    std::cin >> size;

    int numbers [size];

    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }

    int *max = maxsearch(numbers, size);
    std::cout << *max << std::endl;

    return 0;
}

int *maxsearch(int numbers[], int size)
{
    int* temp = &numbers[0];
    for (int i = 0; i < size; ++i) {
        if(numbers[i] > *temp) {
            temp = &numbers[i];
        }
    }
    return temp;
}