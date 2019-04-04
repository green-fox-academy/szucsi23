#include <iostream>

int main() {

    // - Create an array variable named `q`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print the third element of `q`

    int q[] = {4, 5, 6, 7};
    std::cout << q[2] << std::endl;

    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`
    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};
    if (sizeof(p2)> sizeof(p1)) std::cout << p2 << std::endl;

    // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element
    int r[] = {54, 23, 66, 12};
    std::cout << r[1]+r[2] << std::endl;


    return 0;
}