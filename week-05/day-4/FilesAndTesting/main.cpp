#include <iostream>
#include "Decrypter.h"

int main() {
    // Create a program that decrypts the file called "encoded-lines.txt",
    // and pritns the decrypred text to the terminal window.
    Decrypter dec;
    std::cout << "Test1:" << std::endl;
    std::cout << dec.fileToStream("encoded-lines.txt").str() << std::endl;
    std::cout << "Test2:" << std::endl;
    std::cout << dec.fileToStream("empty.txt").str() << std::endl;

    return 0;
}