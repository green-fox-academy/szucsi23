#include <iostream>

int adder(int);
int digits(int);
int power(int, int);
int lnko(int, int);

int main()
{
    //setup
    std::cout << "Give me a number!" << std::endl;
    int x = 0;
    std::cin >> x;
    int result = 0;

    //sum
    result = adder(x);
    std::cout << "Sum of previous numbers: " << result << std::endl;

    //digits sum
    result = digits(x);
    std::cout << "Sum of digits: " << result << std::endl;

    //2. setup
    std::cout << "Give me two numbers!" << std::endl;
    int y = 0;
    std::cin >> x >> y;

    //power
    result = power(x, y);
    std::cout << x << " to the " << y << "'th power is " << result << std::endl;

    //GCD
    result = lnko(x, y);
    std::cout << "The greatest common divisor of "<< x << " and " << y << " is " << result << "." <<std::endl;





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

int lnko(int x, int y)
{
    if(x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    if(x%y==0) {
        return y;
    }
    return lnko(y, x%y);
}