#include <iostream>

int doubling (int);

void greet(std::string);

std::string appendAFunc(std::string);

int sum(int);

void factorio (int, int&);

int swap (int&, int&);

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

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter
    int x = 0;
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> x;
    x = sum(x);
    std::cout << x << std::endl;

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.
    int fx = 3;
    int fy = 0;
    factorio(fx, fy);
    std::cout << fx << " " << fy << std::endl;

    // Create two integer variables: a=15, b=23
    // Create a function named swap that gets the 2 integers as parameters and swaps its values.
    // Print the values before and after the function call and make sure the values are printed in reversed order.
    int a = 15;
    int b = 23;
    std::cout << a << " " << b << std::endl;
    swap(a, b);
    std::cout << a << " " << b << std::endl;

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

int sum (int a) {
    int b = 0;
    for (int i = 0; i <= a; ++i) {
        b += i;
    }
    return b;
}
void factorio (int a, int& b){
    int c = 1;
    for (int i = 0; i < a; ++i) {
        c *= i+1;
    }
    b = c;
}

int swap (int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}