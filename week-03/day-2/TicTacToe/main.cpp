#include <iostream>
#include <fstream>
#include <string>

char ticTacResult(std::string);

char checkline(std::string);


int main()
{
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    std::cout << ticTacResult("..//win-o.txt") << std::endl;
    // should print O

    std::cout << ticTacResult("..//win-x.txt") << std::endl;
    // should print X

    std::cout << ticTacResult("..//draw.txt") << std::endl;
    // should print draw

    return 0;
}

char ticTacResult(std::string filename)
{

    char playfield[3][3];
    char result = 'D';

    std::ifstream file;
    file.open(filename);

    //pulling data from file to array
    std::string row;
    for (int i = 0; getline(file, row); i++) {
        for (int j = 0; j < 3; ++j) {
            playfield[i][j] = row[j];
        }
    }
    file.close();

    //checking rows and columns
    for (int i = 0; i < 3; ++i) {
        std::string line = "";

        for (int j = 0; j < 3; ++j) {
            line += playfield[i][j];
        }
        result = checkline(line);
        if ((result == 'O') || (result == 'X')) return result;

        line = "";
        for (int j = 0; j < 3; ++j) {
            line += playfield[j][i];
        }
        result = checkline(line);
        if ((result == 'O') || (result == 'X')) return result;
    }

    //checking diagonal
    std::string diagonalLeft = "";
    std::string diagonalRight = "";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                diagonalLeft += playfield[i][j];
            }
            if (i+j == 2) {
                diagonalRight += playfield[i][j];
            }
        }
    }
    result = checkline(diagonalLeft);
    if ((result == 'O') || (result == 'X')) return result;
    result = checkline(diagonalRight);
    if ((result == 'O') || (result == 'X')) return result;

    return result;
}

char checkline(std::string str)
{
    if ((str[0] == str[1]) && (str[1] == str[2])) {
        if (str[0] == 'X') {
            return 'X';
        } else return 'O';
    }
    return 'D';
}
