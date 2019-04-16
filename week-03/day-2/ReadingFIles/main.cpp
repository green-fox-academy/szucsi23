#include <iostream>
#include <fstream>
#include <string>

int linecounter(std::string);


int main () {

    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    std::ifstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        myFile.open("my-file.txt");

        std::string text;
        getline(myFile, text);
        std::cout << text << std::endl;

        myFile.close();
    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
    }

    //------------------------------------------------------------------------------------------------------------------

    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    std::string filename = "my-file.txt";
    int a = linecounter(filename);
    std::cout << a;

    return 0;
}

int linecounter(std::string)
{
    std::ifstream myFile;
    int counter = 0;

    try {
        myFile.open("my-file.txt");

        std::string txt;

        while(std::getline(myFile, txt)){
            counter ++;
        }

        myFile.close();
    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
    return counter;
}
