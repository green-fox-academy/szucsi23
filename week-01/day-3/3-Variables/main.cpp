#include <iostream>

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

    std::cout << d << std::endl;

    int e = 8;
    // please cube of e's value

    std::cout << e << std::endl;

    int f1 = 123;
    int f2 = 345;
    // tell if f1 is bigger than f2 (print as a boolean)

    int g1 = 350;
    int g2 = 200;
    // tell if the double of g2 is bigger than g1 (print as a boolean)

    int h = 135798745;
    // tell if it has 11 as a divisor (print as a boolean)

    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)

    int j = 1521;
    // tell if j is dividable by 3 or 5 (print as a boolean)




    return 0;
}