#include <iostream>

std::string xchangey(std::string, int);

int main()
{
    //setup
    std::cout << "Give me a string!" << std::endl;
    std::string str = "";
    std::cin >> str;
    int size = str.length();
    std::string result = "";

    //first
    result = xchangey(str, size);
    std::cout << result << std::endl;


    return 0;
}

std::string xchangey(std::string str, int size)
{
    if(size < 0){
        return str;
    } else if(str[size] == 'x'){
        str[size] = 'y';
    }
    return xchangey(str, size-1);
}