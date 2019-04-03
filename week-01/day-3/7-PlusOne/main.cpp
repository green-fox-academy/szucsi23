#include <iostream>
#include <string>


//  Create a function that takes two strings as a parameter
//  Returns the starting index where the second one is starting in the first one
//  Returns `-1` if the second string is not in the first one

int substr(std::string str, std::string keyword) {
    int poz = 0;
    poz = str.find(keyword);
    if (poz==0) return -1;
    else return poz;
}


int main() {

    // Example

    // Should print: '17'
    std::cout << substr("this is what I'm searching in", "searching") << std::endl;

    // Should print: '-1'
    std::cout << substr("this is what I'm searching in", "not") << std::endl;

    return 0;
}