#include <stdio.h>
#define DISTANCE 345

int main()
{
    // Modifiy this program to print out the number we want
    printf("%d\n", 65);

    // fix the program so it prints out the correct result!
    int seconds = 17;
    float speed = DISTANCE / (float)seconds;
    printf("%f\n", speed);

    // print out the characters that corresponds to these ascii values
    int array[] = { 103, 114, 101, 101, 110, 32, 102, 111, 120};
    for (int i = 0; i < 9; ++i) {
        printf("%c", array[i]);
    }

    return 0;
}