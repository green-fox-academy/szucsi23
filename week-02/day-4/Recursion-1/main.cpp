#include <iostream>

int adder(int);
int digits(int);
int power(int, int);

int main()
{
    std::cout << "Give me a number!" << std::endl;
    int x = 0;
    std::cin >> x;
    int sum = 0;

    sum = adder(x);
    std::cout << "Sum of previous numbers: " << sum << std::endl;


    sum = digits(x);
    std::cout << "Sum of digits: " << sum << std::endl;

    std::cout << "Give me two numbers!" << std::endl;
    int y = 0;
    std::cin >> x >> y;

    sum = power(x, y);
    std::cout << x << " to the " << y << "'th power is " << sum << std::endl;




    return 0;
}

int adder(int x)
{
    if (x <= 1) {
        return x;
    }
    return x + adder(x - 1);
}

int digits(int x)
{
    if ( x / 10 == 0) {
        return x;
    }
    return ((x%10)+digits(x/10));
}

int power(int x, int y)
{
    if(y==1){
        return x;
    }
    return (x = (x * power(x, y-1)));
}