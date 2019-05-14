#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    // Modify this program to greet you instead of the World!
    printf("Hello, Szucsi!\n");

    //------------------------------------------------------------------------------------------------------------------

    // Greet 3 of your classmates with this program, in three separate lines
    // like:
    //
    // Hello, Esther!
    // Hello, Mary!
    // Hello, Joe!
    printf("Hello, Esther!\n");
    printf("Hello, Mary!\n");
    printf("Hello, Joe!\n");

    //------------------------------------------------------------------------------------------------------------------

    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87
    char name[] = "Szucsi";
    int age = 23;
    double height = 1.83;

    printf("%s, %d, %f \n\n", name, age, height);

    //------------------------------------------------------------------------------------------------------------------

    // Create a program that prints a few operations on two numbers: 22 and 13
    int num1 = 22;
    int num2 = 13;
    // Print the result of 13 added to 22
    printf("%d ", num1 + num2);
    // Print the result of 13 substracted from 22
    printf("%d ", num1 - num2);
    // Print the result of 22 multiplied by 13
    printf("%d ", num1 * num2);
    // Print the result of 22 divided by 13 (as a decimal fraction)
    printf("%f ", (double) num1 / num2);
    // Print the reminder of 22 divided by 13
    printf("%d ", num1 % num2);
    // Store the results in variables and use them when you display the result

    //------------------------------------------------------------------------------------------------------------------

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    float a = 0;
    float b = 0;
    float c = 0;
    printf("Give me three numbers!\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    printf("Suface area: %f\n", 2 * a * b + 2 * a * c + 2 * b * c);
    printf("Volume: %f", a * b * c);

    //------------------------------------------------------------------------------------------------------------------

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int stored = rand() % 10;
    int guess;
    int gameOn = 1;
    while (gameOn) {
        printf("Guess the number.\n");
        scanf("%d", &guess);
        if (guess == stored) {
            gameOn = 0;
            printf("You got the number.\n");
        } else if (guess > stored) {
            printf("The stored number is lower.\n");
        } else if (guess < stored) {
            printf("The stored number is higher.\n");
        }

    }

    return 0;
}