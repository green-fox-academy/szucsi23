#include <iostream>
#include <string>

std::string swap(std::string);

int main() {

    std::string str;

    std::cout << "Give me a string." << std::endl;
    std::getline(std::cin,str);

    int size = str.length();
    std::string swapped = swap(str);
    std::cout << str << std::endl;
    std::cout << swapped << std::endl;

    int count = 0;
    std::string temp = "";
    std::string found = "";
    bool foundone = false;


    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; j++) {
            if (str[i] == swapped[j] && !foundone) {
                count++;
                temp += str[i];
                foundone = true;
                if (count >= 3) {
                    found = temp;
                    if (str[i] != swapped[j])foundone = false;
                }
            }


        }

    }

    std::cout << found << std::endl;

    return 0;
}

std::string swap(std::string str)
{
    int size = str.length();
    std::string swapped = "";

    for (int i = 0; i < size; ++i) {
        swapped += str[size-i-1];

    }

    return swapped;
}