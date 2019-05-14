#include <iostream>

int *min(int[], int);
void swap (int&, int&);

int main() {

    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int size = sizeof(numbers)/ sizeof(int);

    int *minimum = min(numbers, size);

    std::cout << *minimum << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;
    swap(a, b);

    std::cout << a << " " << b << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    // Refactor time!
    // use your 'refactor_maximum.cpp', solve the same exercise by creating a separate function
    // for each functionality

    //???

    return 0;
}

int *min(int numbers[], int size)
{
    int *temp = &numbers[0];
    for (int i = 0; i < size; ++i) {
        if(numbers[i] < *temp) {
            *temp = numbers[i];
        }
    }
    return temp;
}

void swap (int &a, int &b) {
    int c = 0;
    c = a;
    a = b;
    b = c;

}