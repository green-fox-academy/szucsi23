#include <iostream>

int main()
{
    int a = 10;
    int b = 0;
    std::cin >> b;
    int c = 0;

    try {
        if (b == 0) {
            throw std::string("Micsinász?");
        }
        c = a / b;
    std::cout << c << std::endl;
    } catch (std::string hiba){
        std::cout << hiba;
    }

    return 0;
}