#include <iostream>

int main() {
    // Create a program that writes this line 100 times:
    // "I won't cheat on the exam!"
    for (int i = 0; i < 100; ++i) {
        std::cout << "I won't cheat on the exam!" << std::endl;
    }

    //-----------------------------------------------------------------------------------------------------------------

    // Create a program that prints all the even numbers between 0 and 500
    for (int i = 0; i <= 500; ++i) {
        if (i % 2 == 0) std::cout << i << std::endl;
    }

    //-----------------------------------------------------------------------------------------------------------------

    // Create a program that asks for a number and prints the multiplication table with that number
    int x = 0;
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> x;
    for (int i = 0; i < 10; ++i) {
        std::cout << i + 1 << " * " << x << " = " << (i + 1) * x << std::endl;
    }

    //-----------------------------------------------------------------------------------------------------------------

    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    int num1, num2;
    std::cout << "Please give me two numbers!" << std::endl;
    std::cin >> num1 >> num2;
    if (!(num2 > num1)) {
        std::cout << "The second number should be bigger" << std::endl;
    } else {
        for (int i = num1; i < num2; ++i) {
            std::cout << i << std::endl;
        }
    }

    //-----------------------------------------------------------------------------------------------------------------

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.
    for (int i = 0; i < 100; ++i) {
        if ((i+1) % 3 == 0 && (i+1) % 5 == 0) {
            std::cout << "FizzBuzz" << std::endl;
        } else if ((i+1)%3==0) {
            std::cout << "Fizz" << std::endl;
        } else if ((i+1)%5==0) {
            std::cout << "Buzz" << std::endl;
        } else {std::cout << i+1 << std::endl;}
    }

    //-----------------------------------------------------------------------------------------------------------------

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:

    int tside = 0;
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> tside;
    for (int i = 0; i < tside; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    //-----------------------------------------------------------------------------------------------------------------

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    int ph = 0;
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> ph;
    int cs=1;
    for (int i = 0; i < ph; ++i) {

        for (int j = 0; j <= ph-i; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < cs; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
        cs +=2;
    }


    //-----------------------------------------------------------------------------------------------------------------


    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:

    int dh = 0;
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> dh;
    int st=1;
    for (int i = 0; i < dh; ++i) {

        for (int j = 0; j <= dh-i; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < st; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}