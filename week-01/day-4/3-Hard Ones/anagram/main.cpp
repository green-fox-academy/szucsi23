#include <iostream>

bool anagram (std::string, std::string);

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

    int size = in1.length();
    bool yup = true;


    bool Checked[size];
    for (int i = 0; i < size; i++) Checked[i] = false;

    for (int i = 0; i < size; i++) {
        if (Checked[i] == false) {
            for (int j = 0; j < size; ++j) {
                if (in1[i] == in2[j]) {

                    Checked[i] = true;
                }
            }

        }
    }

    for (int i = 0; i < size; ++i) {
        if (Checked[i] == false) yup = false;
    }
    return yup;
}