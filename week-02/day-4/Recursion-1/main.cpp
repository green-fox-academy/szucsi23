#include <iostream>

int adder(int);
int digits(int);

int main()
{
    int x = 0;
    std::cin >> x;
    int sum = 0;

    sum = adder(x);
    std::cout << "Sum of previous numbers: " << sum << std::endl;


    sum = digits(x);
    std::cout << "Sum of digits: " << sum << std::endl;





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
    if ( x <= 1) {
        return x;
    }
    return ((x%10)+digits(x/10));
}
