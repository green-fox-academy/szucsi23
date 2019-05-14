#include <iostream>
#include <string>

int main() {

    std::string str;

    std::cout << "Give me a string." << std::endl;
    std::cin >> str;

    int size = str.length();
    int count = 0;
    int si=0;
    int sj=0;
    std::string pal = "";
    bool saved = false;

    for (int i = 0; i < size; ++i) {
        for (int j = size; j > 0; j--) {
            if(str[i] == str [j]) {
                if(!saved){
                    si=i;
                    sj=j;
                    saved = true;
                }
                count ++;
                break;
            }

        }
    }
    if (count >=3) {
        for (int k = si; k <= sj; ++k) {
            pal += str [k];
        }

    }
    std::cout << pal << std::endl;
    
    return 0;
}