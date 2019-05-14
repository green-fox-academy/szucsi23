#include <iostream>
#include <exception>
#include <string>
#include <fstream>

void funckit (std::string, std::string, int);


int main()
{
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    std::ofstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        myFile.open("my-file.txt");

        std::string str = "your name \n";
        myFile << str;

        myFile.close();
    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
    }

    //------------------------------------------------------------------------------------------------------------------

    // Create a function that takes 3 parameters: a path, a word and a number
    // and is able to write into a file.
    // The path parameter should be a string that describes the location of the file you wish to modify
    // The word parameter should also be a string that will be written to the file as individual lines
    // The number parameter should describe how many lines the file should have.
    // If the word is "apple" and the number is 5, it should write 5 lines
    // into the file and each line should read "apple"

    std::string path = "C:\\Users\\hun46\\Documents\\Programming\\GreenFox\\szucsi23\\week-03\\day-2\\FileWriting\\alma.txt";
    std::string word = "alma";
    int num = 3;

    funckit(path, word, num);
    return 0;
}

void funckit(std::string path, std::string word, int num)
{
    std::ofstream file;
    file.open(path);
    for (int i = 0; i < num; ++i) {
        file << word << std::endl;
    }
}
