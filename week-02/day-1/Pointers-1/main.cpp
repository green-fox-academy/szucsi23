#include <iostream>

int main() {

    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *pInt = &a;
    double *pDouble = &b;
    std::string *pString = &name;

    std::cout << *pInt << " " << *pDouble << " " << *pString << std::endl;


    //------------------------------------------------------------------------------------------------------------------

    // Print out the value of the variable called 'age' using a pointer
    // (you have to create the pointer first)

    int age = 31;
    int *ageptr = &age;
    std::cout << *ageptr << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    float *temperatureptr = &temperature;
    *temperatureptr = 23;

    //------------------------------------------------------------------------------------------------------------------

    // Add two numbers using pointers

    int x = 20;
    int y = 17;

    int *xptr = &x;
    int *yptr = &y;
    int sum = 0;
    sum = *xptr + *yptr;

    std::cout << sum << std::endl;


    return 0;
}