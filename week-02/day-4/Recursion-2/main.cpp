#include <iostream>

int earcounter(int);
int advancedearcounter(int);

int main()
{
    std::cout << "Give me a number!" << std::endl;
    int x = 0;
    std::cin >> x;
    int result = 0;

    //bunnyears
    result = earcounter(x);
    std::cout << x << " bunnies have " << result << " ears." <<std::endl;

    //strange bunnyears
    result = advancedearcounter(x);
    std::cout << x << " retarded bunnies have " << result << " ears." <<std::endl;


    return 0;
}

int earcounter(int bunnies)
{
    if(bunnies == 1){
        return 2;
    }
    return 2 + earcounter(bunnies -1);
}

int advancedearcounter(int number)
{
    if(number == 1){
        return 3;
    } else if(number%2==1){
        return 3 + advancedearcounter(number -1);
    } else {
        return 2 + advancedearcounter(number -1);
    }

}