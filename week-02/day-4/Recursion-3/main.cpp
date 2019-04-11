#include <iostream>

std::string xchangey(std::string, int);
std::string xremove(std::string, int);
std::string addstar(std::string, int);

int main()
{
    //setup
    std::cout << "Give me a string!" << std::endl;
    std::string str = "";
    std::cin >> str;
    int size = str.length();
    std::string result = "";

    //change
    result = xchangey(str, size);
    std::cout << result << std::endl;

    //remove
    result = xremove(str, size);
    std::cout << result << std::endl;

    //addstar
    result = addstar(str, size);
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

std::string xremove(std::string str, int size)
{
    int i = 0;
    if(size < 0){
        return str;
    } else if(str[size] == 'x'){
        str.erase(size, 1);
    }
    return xremove(str, size-1);
}

std::string addstar(std::string str, int size)
{
    int i = 0;
    if(size < 0){
        return str;
    } else if(str[size] == 'x'){
        str.erase(size, 1);
    }
    return xremove(str, size-1);
}