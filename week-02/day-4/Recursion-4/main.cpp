#include <iostream>

int fibonacci(int);

int max(int[], int);

int main()
{
    //setup
    std::cout << "Give me a number!" << std::endl;
    int x = 0;
    std::cin >> x;
    int result = 0;

    //fibonacci
    result = fibonacci(x);
    std::cout << result << std::endl;

    int arr[] = {1, 13, 1, 46, 23, 3, 6, 4, 67, 2, 324, 42};
    int size = sizeof(arr) / sizeof(int);
    result = max(arr, size);
    std::cout << result << std::endl;

    return 0;
}

int fibonacci(int n)
{
    if (n-2 <=1) { //todo: vagy maybe???
        return 1;
    } else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int max(int arr[], int size)
{
    int temp = 0;
    if (size == 1) {
        return arr[0];
    }

    temp = max(arr, size - 1);

    if (arr[size - 1] > temp) {
        temp = arr[size - 1];
    }
    return temp;
}