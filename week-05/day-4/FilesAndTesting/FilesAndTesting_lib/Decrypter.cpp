//
// Created by hun46 on 2019. 05. 02..
//

#include "Decrypter.h"

void Decrypter::fileToOutput(std::string fileName)
{
    std::ifstream myFile;
    myFile.exceptions(std::ifstream::badbit);
    try {
        myFile.open(fileName);
        std::string oneLine;
        while(getline(myFile, oneLine)){
            for (int i = 0; i < oneLine.length(); ++i) {
                if(oneLine[i] != ' ') oneLine[i]--;
            }
            std::cout << oneLine << std::endl;
        }

    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
    }
}
