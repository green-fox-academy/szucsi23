#include <iostream>

int doubling (int);

void greet(std::string);

std::string appendAFunc(std::string);

int main() {

    // - Create an integer variable named `baseNum` and assign the value `123` to it
    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
    // - Print the result of `doubling(baseNum)`
    int baseNum = 123;
    baseNum = doubling(baseNum);
    std::cout << baseNum << std::endl;

    // - Create a string variable named `al` and assign the value `Greenfox` to it
    // - Create a function called `greet` that greets it's input parameter
    // - Greeting is printing e.g. `Greetings dear, Greenfox`
    // - Greet `al`
    std::string al = "Greenfox";
    greet(al);

    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    // - Write a function called `appendAFunc` that gets a string as an input,
    //   appends an 'a' character to its end and returns with a string
    //
    // - Print the result of `appendAFunc(typo)`
    std::string typo = "Chinchill";
    typo = appendAFunc (typo);
    std::cout << typo << std::endl;




    return 0;
}

int doubling (int a) {
    return (a*2);
}

void greet (std::string a) {
    std::cout << "Welcome, dear "  << a << "!" << std::endl;
}

std::string appendAFunc(std::string a) {
    return (a += "a");
}