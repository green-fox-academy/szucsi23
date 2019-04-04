#include <iostream>

bool anagram (std::string, std::string);
std::string abc(std::string);

int main() {

    std::string word1;
    std::string word2;

    std::cout << "Give me two words." << std::endl;
    std::cin >> word1 >> word2;

    bool namivan = anagram(word1, word2);

    if (namivan) std::cout << "These two are anagrams." << std::endl;
    else std::cout << "These are not anagrams of eachoder." << std::endl;

    return 0;
}

bool anagram (std::string in1, std::string in2) {

    if(in1.length() != in2.length()) return false;

    int size = in1.length();
    bool yup = true;

    std::string temp1 = abc(in1);
    std::string temp2 = abc(in2);

    for (int i = 0; i < size; ++i) {
        if (temp1[i] != temp2[i]) yup = false;
    }



    return yup;
}

std::string abc (std::string str) {
    int size = str.length();
    char temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    return str;
}