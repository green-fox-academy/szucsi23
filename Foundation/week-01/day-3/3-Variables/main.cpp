#include <iostream>
#include <cmath>

int main() {

    // Store your favorite number in a variable (as an integer)
    // And print it like this: "My favorite number is: 8"
    int favnum = 23;
    std::cout << "My favourite number is: " << favnum << std::endl;

    // Swap the values of the variables
    int x = 123;
    int y = 526;

    int z = x;
    x = y;
    y = z;

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    // Print the Body mass index (BMI) based on these values
    double massInKg = 81.2;
    double heightInM = 1.78;

    std::cout << "BMI: " << massInKg/(heightInM*heightInM) << std::endl;

    // Define several things as a variable then print their values
    // Your name as a string
    std::string name = "Szucsi";
    // Your age as an integer
    int age = 23;
    // Your height in meters as a double
    double height = 1.83;
    // Whether you are married or not as a boolean
    bool married = false;

    std::cout << name << " " << age << " " << height << " " << married << std::endl;


    int a = 3;
    // make the "a" variable's value bigger by 10
    a += 10;
    std::cout << a << std::endl;

    int b = 100;
    // make b smaller by 7
    b -= 7;
    std::cout << b << std::endl;

    int c = 44;
    // please double c's value
    c*=2;
    std::cout << c << std::endl;

    int d = 125;
    // please divide by 5 d's value
    d/=(5*d);
    std::cout << d << std::endl;

    int e = 8;
    // please cube of e's value
    e=e*e*e;
    std::cout << e << std::endl;

    int f1 = 123;
    int f2 = 345;
    // tell if f1 is bigger than f2 (print as a boolean)
    std::cout << (f1>f2) << std::endl;

    int g1 = 350;
    int g2 = 200;
    // tell if the double of g2 is bigger than g1 (print as a boolean)
    std::cout << (g1 < (2*g2)) << std::endl;

    int h = 135798745;
    // tell if it has 11 as a divisor (print as a boolean)
    std::cout << ((h%11)==0) << std::endl;

    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)
    std::cout << (i1>(i2*i2) && i1<(i2*i2*i2)) << std::endl;

    int j = 1521;
    // tell if j is dividable by 3 or 5 (print as a boolean)
    std::cout << ((j%3==0)|| (j%5)==0) << std::endl;

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double wid = 13;
    double len = 42;
    double hei = 23;
    std::cout << "Surface Area: " << ((2*wid*len)+(2*wid*hei)+(2*len*hei)) << std::endl;
    std::cout << "Volume: " << (wid*len*hei) << std::endl;


    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables
    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    std::cout << (((24-currentHours)*60-currentMinutes)*60-currentSeconds) << std::endl;


    return 0;
}