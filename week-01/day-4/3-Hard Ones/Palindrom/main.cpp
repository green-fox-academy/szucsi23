#include <iostream>
#include <string>

int main() {

    std::string word;
    std::string copy;

    std::cout << "Give me a word." << std::endl;
    std::cin >> word;
    copy = word;

    int size = word.length();

    for (int i = 0; i < size; ++i) {
        copy[i] = word[size-i-1];
    }
    std::cout << word << copy << std::endl;

    return 0;
}