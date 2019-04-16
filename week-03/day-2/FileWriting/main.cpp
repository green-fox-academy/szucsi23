#include <iostream>
#include <exception>
#include <string>
#include <fstream>

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


    return 0;
}