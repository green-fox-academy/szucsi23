//
// Created by hun46 on 2019. 05. 02..
//

#include "Decrypter.h"

std::stringstream Decrypter::fileToStream(std::string fileName)
{
    std::ifstream myFile;
    myFile.exceptions(std::ifstream::badbit);
    try {
        myFile.open(fileName);
        if(!myFile.is_open()) {
            throw std::string ("File in't opened.");
        }
        if(myFile.peek() == std::ifstream::traits_type::eof()) {
            throw std::string ("File is empty.");
        }
        std::string oneLine;
        std::stringstream stream;

        while(getline(myFile, oneLine)){
            for (int i = 0; i < oneLine.length(); ++i) {
                if(oneLine[i] != ' ') oneLine[i]--;
            }
            stream << oneLine << std::endl;
        }
        return stream;
    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
    } catch (std::string exception) {
        std::cout << exception << std::endl;
    }
}
