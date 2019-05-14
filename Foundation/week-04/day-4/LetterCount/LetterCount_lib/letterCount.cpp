//
// Created by hun46 on 2019. 04. 25..
//

#include "letterCount.h"

std::map<char, int> letterCount(std::string str)
{
    std::string inOrder = abc(str);

    int numberOf = 1;
    std::map<char, int> dictionary;

    for (int i = 0; i < inOrder.size(); ++i) {
        if(inOrder[i] == inOrder[i+1]){
            numberOf++;
        } else {
            dictionary.insert(std::pair<char, int>(inOrder[i], numberOf));
            numberOf = 1;
        }
    }

    return dictionary;
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