#include <iostream>

int main() {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output
    int x = 4;
    int y = 4;

    int matrix [x][y];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if(i==j) matrix[i][j] = 1;
            else matrix[i][j] = 0;
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }


    return 0;
}