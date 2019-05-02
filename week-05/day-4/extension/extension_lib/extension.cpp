//
// Created by hun46 on 2019. 05. 02..
//

#include "extension.h"

#include <algorithm>
#include <sstream>

int add(int a, int b)
{
    return a + b;
}

int maxOfThree(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else return c;
}

int median(const std::vector<int> &pool)
{
    int sum = 0;
    for (int i = 0; i < pool.size(); ++i) {
        sum += pool[i];
    }
    return (sum / pool.size());
}

bool isVowel(char c)
{
    static const std::vector<char> vowels = {'a', 'u', 'o', 'e', 'i'};

    return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
}

std::vector<std::string> split(const std::string &str, char delim)
{
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> v;
    while (std::getline(ss, token, delim)) {
        v.push_back(token);
    }

    return v;
}

std::string join(const std::string &separator, const std::vector<std::string> &array)
{
    std::stringstream ss;
    for (int i = 0; i < array.size(); ++i) {
        ss << array[i];
        if (i != array.size() - 1) {
            ss << separator;
        }
    }

    return ss.str();
}

std::string translate(const std::string &hungarian)
{
    std::string teve = hungarian;
    int length = teve.size();
    for (int i = 0; i < length; i++) {
        const char c = teve.at(i);
        if (isVowel(c)) {
            teve = join(std::string(1, c) + "v" + std::string(1, c), split(teve, c));
            i += 2;
            length += 2;
        }
    }
    return teve;
}