#include <iostream>
#include <fstream>
#include <string>
#include "Decrypter.h"

int main() {
    // Create a program that decrypts the file called "encoded-lines.txt",
    // and pritns the decrypred text to the terminal window.
    Decrypter dec;
    dec.fileToOutput("encoded-lines.txt");
    return 0;
}