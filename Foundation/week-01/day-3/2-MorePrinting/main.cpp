#include <iostream>

int main() {

    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)

    std::cout << "Szücsi" << std::endl;
    std::cout << "23" << std::endl;
    std::cout << "1.83m" << std::endl;

    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22
    std::cout << 13+22 << std::endl;
    // Print the result of 13 substracted from 22
    std::cout << 22-13 << std::endl;
    // Print the result of 22 multiplied by 13
    std::cout << 22*13 << std::endl;
    // Print the result of 22 divided by 13 (as a decimal fraction)
    std::cout << 22.0/13.0 << std::endl;
    // Print the integer part of 22 divided by 13
    std::cout << 13/22 << std::endl;
    // Print the reminder of 22 divided by 13
    std::cout << 22%13 << std::endl;

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //

    std::cout << "Hours spent with coding: " << (17*5)*6 << std::endl;

    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52
    std::cout << ((17.0*5.0*6.0)/(17.0*52.0))*100 << "%" << std::endl;

    return 0;
}