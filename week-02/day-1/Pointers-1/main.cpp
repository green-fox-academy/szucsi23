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
    std::cout << *age << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    


    return 0;
}