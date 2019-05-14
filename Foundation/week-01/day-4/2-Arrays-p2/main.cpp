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

    int matrix[x][y];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (i == j) matrix[i][j] = 1;
            else matrix[i][j] = 0;
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array
    int numList[] = {3, 4, 5, 6, 7};
    for (int i = 0; i < (sizeof(numList) / sizeof(int)); ++i) {
        numList[i] *= 2;
    }

    // - Create a two dimensional array
    //   which can contain the different shades of specified colors
    // - In `colors[0]` store the shades of green:
    //   `"lime", "forest green", "olive", "pale green", "spring green"`
    // - In `colors[1]` store the shades of red:
    //   `"orange red", "red", "tomato"`
    // - In `colors[2]` store the shades of pink:
    //   `"orchid", "violet", "pink", "hot pink"`
    std::string colors[3][5] = {
            {"lime",       "forest green", "olive", "pale green", "spring green"},
            {"orange red", "red",          "tomato"},
            {"orchid",     "violet",       "pink",  "hot pink"}
    };

    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end
    std::string animals[] = {"koal", "pand", "zebr"};
    for (int i = 0; i < 3; ++i) {
        animals[i] += "a";
    }

    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`
    std::string abc[] = {"first", "second", "third"};
    std::string temp = abc[0];
    abc[0] = abc[2];
    abc[2] = temp;

    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`
    int ai[] = {3, 4, 5, 6, 7};
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += ai[i];
    }
    std::cout << sum << std::endl;

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`
    int aj[] = {3, 4, 5, 6, 7};
    int size = sizeof(aj) / sizeof(int);
    int temp_arr[size];

    for (int i = 0; i < size; ++i) {
        std::cout << aj[i];
    }
    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {
        temp_arr[i] = aj[i];
        std::cout << temp_arr[i];
    }
    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {
        aj[i] = temp_arr[size - 1 - i];
        std::cout << aj[i];
    }
    std::cout << std::endl;

    return 0;
}