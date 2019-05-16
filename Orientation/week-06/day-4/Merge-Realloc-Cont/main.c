#include <stdio.h>
#include <stdlib.h>

char* concatenate(char* first, char* second);
char *read_string();

int main()
{
/*
    // please allocate a 10 long array and fill it with even numbers
    // please allocate a 10 long array and fill it with odd numbers
    // select an array, and push the elements into the another array
    // print the array in descending order
    // delete the arrays after you don't use them

    int* odd = NULL;
    odd = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        odd[i] = (i*2)+1;
    }

    int* even = NULL;
    even = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        even[i] = (i*2);
    }

    odd = realloc(odd, sizeof(int) * 20);

    for (int j = 10; j < 20; ++j) {
        odd[j] = even[j-10];
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20-1-i; ++j) {
            if (odd[j] > odd[j+1]) {
                int temp = odd[j];
                odd[j] = odd[j+1];
                odd[j+1] = temp;
            }
        }
    }

    for (int k = 0; k < 20; ++k) {
        printf("%d ", odd[k]);
    }
    free(odd);
    odd = NULL;
    free(even);
    even = NULL;

    //------------------------------------------------------------------------------------------------------------------
    // Prompt the user to enter a number. -> This number will be X.
    // Allocate memory for X numbers.
    // Prompt the user to enter X numbers.
    // Allocate memory for Y numbers, which is the sum of the X numbers.
    // Fill that array with from 1 to Y, then print them.

    printf("\nPlease gie me a number.\n");
    int x;
    scanf("%d", &x);
    int *ptr = (int*)malloc(sizeof(int) * x);
    int y = 0;

    printf("\nNow please gie me %d numbers.\n", x);
    for (int i = 0; i < x; ++i) {
        scanf("%d", &ptr[i]);
        y += ptr[i];
    }

    int *ptr_2 = (int*)malloc(sizeof(int) * y);
    for (int i = 0; i < y; ++i) {
        ptr_2[i] = i+1;
    }

    printf("\n");

    for (int i = 0; i < x; ++i) {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    for (int i = 0; i < y; ++i) {
        printf("%d ", ptr_2[i]);
    }

    printf("\n");

    free(ptr);
    ptr = NULL;
    free(ptr_2);
    ptr_2 = NULL;

*/
    //------------------------------------------------------------------------------------------------------------------
    // write a function which takes 2 strings as parameter, concatenates them together and returns it back.
    // Test it for long and empty strings as well.
    // Try to use the least amount of memory that's possible.

    printf("\nPlease give me the first string:\n");
    char *first = read_string();
    printf("\nPlease give me the first string:\n");
    char *second = read_string();

    char *mix = concatenate(first, second);

    printf("%s", mix);

    free(first);
    first = NULL;
    free(second);
    second = NULL;
    free(mix);
    mix = NULL;

    return 0;
}

char *concatenate(char *first, char *second)
{
    int first_size = 0;
    int second_size = 0;
    for (int i = 0; first[i] != '\0'; ++i) {
        first_size = i+2;
    }
    for (int i = 0; second[i] != '\0'; ++i) {
        second_size = i+2;
    }


    first = realloc(first, sizeof(char)*(first_size+second_size-1));

    for (int i = 0; i < (second_size); ++i) {
        first[i+first_size-1] = second[i];
    }

    return first;
}

char *read_string()
{
    size_t size = 1;
    char *string = (char *)calloc(size, sizeof(char));

    // Read a character from the standard input
    char c = getc(stdin);

    // Check if the character is not '\n'
    while (c != '\n') {
        // Reallocate the memory for the string to fit one more character
        size++;
        string = (char *) realloc(string, size * sizeof(char));

        // Append the character to the end of the string
        string[size - 2] = c;

        // Append a '\0' to the end of the string
        string[size - 1] = '\0';

        // Repeat
        c = getc(stdin);
    }

    return string;
}