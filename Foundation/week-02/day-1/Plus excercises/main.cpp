#include <iostream>
#include <ctime>

std::string find(std::string);

bool isPalindrom(std::string);

std::string swapper(std::string str);

int main() {

    //Óra setup
    std::clock_t start;
    double duration;

    std::string str;

    std::cout << "Give me a string." << std::endl;
    std::getline(std::cin, str);

    int size = str.length();

    //Óra indul
    start = std::clock();

    std::string palindroms = find(str);

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    //Óra megáll


    std::cout << palindroms << std::endl;
    std::cout << std::endl << duration << std::endl;


    return 0;
}

std::string find(std::string str) {
    std::string collecting = "";
    std::string temp = "";
    int size = str.length();

    for (int pl = 3; pl < size; ++pl) {
        for (int j = 0; j <size-pl; ++j) {
            for (int i = j; i < pl+j; ++i) {
                temp += str[i];
            }
            if (isPalindrom(temp)) {
                collecting += temp;
                collecting += " | ";
            }
            temp = "";
        }
    }
    return collecting;
}

bool isPalindrom(std::string str) {
    bool itsgood = true;
    std::string swapped = swapper(str);
    int size = str.length();
    for (int i = 0; i < size && itsgood; ++i) {
        if (str[i] != swapped[i]) {
            itsgood = false;
        }
    }
    return itsgood;
}

std::string swapper(std::string str) {
    int size = str.length();
    std::string swapped = "";

    for (int i = 0; i < size; ++i) {
        swapped += str[size - i - 1];

    }

    return swapped;
}