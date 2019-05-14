#include <stdio.h>

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

#include "circle.h"

int main()
{
    int r = 3;
    printf("The circumference is: %lf \n", circumference(r));
    printf("The area is: %lf \n", area(r));

    return 0;
}

