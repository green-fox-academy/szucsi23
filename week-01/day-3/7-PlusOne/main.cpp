#include <iostream>
#include <cstring>


//  Create a function that takes two strings as a parameter
//  Returns the starting index where the second one is starting in the first one
//  Returns `-1` if the second string is not in the first one

int substr1(std::string str, std::string keyword) {
    int poz = 0;
    poz = str.find(keyword);
    if (poz==0) return -1;
    else return poz;
}

int substr2(std::string str, std::string keyword) {
    for (int i = 0; i < keyword.length(); ++i) {
        for (int j = 0; j < str.length(); ++j) {
            if (keyword[i] == str[j]){
                
            }
        }
        
    }
}


int main() {

    // Example

    // Should print: '17'
    std::cout << substr1("this is what I'm searching in", "searching") << std::endl;

    // Should print: '-1'
    std::cout << substr1("this is what I'm searching in", "not") << std::endl;

    // Should print: '17'
    std::cout << substr2("this is what I'm searching in", "searching") << std::endl;

    // Should print: '-1'
    std::cout << substr2("this is what I'm searching in", "not") << std::endl;

    return 0;
}