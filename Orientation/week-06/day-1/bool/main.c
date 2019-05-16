#include <stdio.h>
#include "math.h"

int old_enough(int age);

int is_equal(int a, int b);

int odd_or_even(int a);

int sum_of_digits(int a, int b);

int is_prime(int b);

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age;
    printf("How old are you?\n");
    scanf("%d", &age);
    if (old_enough(age)) {
        printf("You are allowed to dring.\n");
    } else {
        printf("You are not allowed to dring.\n\n");
    }

    //------------------------------------------------------------------------------------------------------------------
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int a, b;
    printf("Give me two numbers\n");
    scanf("%d %d", &a, &b);
    if (is_equal(a, b)) {
        printf("These numbers are equal.\n");
    } else {
        printf("These numbers are not equal.\n");
    }

    //------------------------------------------------------------------------------------------------------------------
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    if (odd_or_even(a)) {
        printf("And the first number is an even number.\n");
    } else {
        printf("And the first number is an odd number.\n");
    }

    //------------------------------------------------------------------------------------------------------------------
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    if (sum_of_digits(a, b)) {
        printf("The sum of the digits of the two numbers are equal.\n");
    } else {
        printf("The sum of the digits of the two numbers are not equal.\n");
    }

    //------------------------------------------------------------------------------------------------------------------
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    if (is_prime(b)) {
        printf("And the second number is not a prime number.\n");
    } else {
        printf("And the second number is a prime number.\n");
    }

    //------------------------------------------------------------------------------------------------------------------
    return 0;
}


int old_enough(int age)
{
    return (age >= 18);
}

int is_equal(int a, int b)
{
    return (a == b);
}

int odd_or_even(int a)
{
    return (!(a % 2));
}

int sum_of_digits(int a, int b)
{
    int temp, remainder;
    int a_sum = 0;
    int b_sum = 0;

    temp = a;
    while (temp != 0) {
        remainder = temp % 10;
        a_sum = a_sum + remainder;
        temp = temp / 10;
    }

    temp = b;
    while (temp != 0) {
        remainder = temp % 10;
        b_sum = b_sum + remainder;
        temp = temp / 10;
    }

    return (is_equal(a_sum, b_sum));
}

int is_prime(int b)
{
    for (int i = 1; i < sqrt(b); ++i) {
        if((b % i) == 0) {
            return 0;
        }
    }
    return 1;
}
