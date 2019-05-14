#include <iostream>

int main() {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.
    int num1 = 0;
    std::cout << "Please give me a number" << std::endl;
    std::cin >> num1;
    if (num1 % 2 == 0) {
        std::cout << "It's an even number" << std::endl;
    } else {
        std::cout << "It's an odd number" << std::endl;
    }

//----------------------------------------------------------------------------------------------------------------------

    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot
    int num2 = 0;
    std::cout << "Please give me a number" << std::endl;
    std::cin >> num2;
    if (num2 <= 0) {
        std::cout << "Not enough" << std::endl;
    } else if (num2 == 1) {
        std::cout << "One" << std::endl;
    } else if (num2 == 2) {
        std::cout << "Two" << std::endl;
    } else if (num2 > 2) {
        std::cout << "A lot" << std::endl;
    }

//----------------------------------------------------------------------------------------------------------------------

    // Write a program that asks for two numbers and prints the bigger one
    int num3, num4;
    std::cout << "Please give me two numbers" << std::endl;
    std::cin >> num3 >> num4;
    if (num3 > num4) {
        std::cout << "the bigger is: " << num3 << std::endl;
    } else if (num4 > num3) {
        std::cout << "the bigger is: " << num4 << std::endl;
    } else std::cout << "They are even" << std::endl;

    // Write a program that asks for two numbers
    // The first number represents the number of girls that comes to a party, the
    // second the boys
    int girls = 0;
    int boys = 0;
    std::cout << "Please give me the number of the girls and the number of the boys in your party." << std::endl;
    std::cin >> girls >> boys;

    if (girls == 0) {
        // It should print: Sausage party
        // If no girls are coming, regardless the count of the people
        std::cout << "Sausage party!" << std::endl;
    } else if ((girls + boys) >= 20 && girls == boys) {
        // It should print: The party is excellent!
        // If the the number of girls and boys are equal and 20 or more people are coming to the party
        std::cout << "The party is excellent!" << std::endl;
    } else if ((girls + boys) >= 20 && (girls % boys) != 0) {
        // It should print: Quite cool party!
        // If there are 20 or more people coming to the party but the girl - boy ratio is not 1-1
        std::cout << "Quite cool party!" << std::endl;
    } else if ((girls + boys) < 20) {
        // It should print: Average party...
        // If there are less people coming than 20
        std::cout << "Average party..." << std::endl;
    }

//----------------------------------------------------------------------------------------------------------------------

    double a = 24;
    int out = 0;
    // if a is even increment out by one
    if (((int) a % 2) == 0) out++;
    std::cout << out << std::endl;


    int b = 13;
    std::string out2 = "";
    // if b is between 10 and 20 set out2 to "Sweet!"
    // if less than 10 set out2 to "Less!",
    // if more than 20 set out2 to "More!"
    if (b < 10) {
        out2 = "Less!";
    } else if (10 <= b <= 20) {
        out2 = "Sweet!";
    } else if (20 < b) {
        out2 = "More!";
    }
    std::cout << out2 << std::endl;


    int c = 123;
    int credits = 100;
    bool isBonus = false;
    if (credits >= 50 && !isBonus) {
        // if credits are at least 50,
        // and isBonus is false decrement c by 2
        c -= 2;
    } else if (credits < 50 && !isBonus) {
        // if credits are smaller than 50,
        // and isBonus is false decrement c by 1
        c--;
    } else if (isBonus) {
        // if isBonus is true c should remain the same
    }
    std::cout << c << std::endl;


    int d = 8;
    int time = 120;
    std::string out3 = "";
    if (d%4==0 && time<=200) {
        // if d is dividable by 4
        // and time is not more than 200
        // set out3 to "check"
        out3="check";
    } else if (time>200) {
        // if time is more than 200
        // set out3 to "Time out"
        out3="Time out";
    } else { out3= "Run Forest Run!"}
    // otherwise set out3 to "Run Forest Run!"


    std::cout << out3 << std::endl;


    return 0;
}