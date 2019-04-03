#include <iostream>

int main() {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::string user;
    std::cout << "Please wrtie your name here:" << std::endl;
    std::cin >> user;
    std::cout << "Hello " << user << std::endl;

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    int dist = 0;
    std::cout << "pPlease write a distance in km." << std::endl;
    std::cin >> dist;
    std::cout << "It's " << 0.6213*dist << " miles." << std::endl;

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int chicks = 0;
    int cows = 0;
    std::cout << "How many chickens and cows do you have?" << std::endl;
    std::cin >> chicks >> cows;
    std::cout << "That's this many legs: " << chicks*2+cows*4 << std::endl;


    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:

    int a, b, c, d, e;
    std::cout << "Please give me 5 integers!" << std::endl;
    std::cin >> a >> b >> c >> d >> e;
    std::cout << "Sum: " << a+b+c+d+e << ", Average: " << (a+b+c+d+e)/5.0 << std::endl;


    return 0;
}