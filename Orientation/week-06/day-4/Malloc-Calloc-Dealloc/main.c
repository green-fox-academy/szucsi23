#include <stdio.h>
#include <stdlib.h>




int main()
{
    // with malloc
    // please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
    // please delete the array before the program exits

    int* pointer = (int*)malloc(sizeof(int) * 10);

    for (int i = 0; i < 5; ++i) {
        pointer[i] = i;
    }

    printf("\nPrinting with malloc:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d, ", pointer[i]);
    }

    free(pointer);
    pointer = NULL;

    //------------------------------------------------------------------------------------------------------------------
    // with calloc
    // please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
    // please delete the array before the program exits
    // what's the difference between this and the previous excersice?

    pointer = (int*)calloc(sizeof(int), 10);

    for (int i = 0; i < 5; ++i) {
        pointer[i] = i;
    }

    printf("\n\nPrinting with calloc:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d, ", pointer[i]);
    }

    free(pointer);
    pointer = NULL;

    //------------------------------------------------------------------------------------------------------------------
    // with malloc
    // please allocate a 10 long array and fill it with even numbers then print the whole array
    // please deallocate memory without using free

    pointer = (int*)malloc(sizeof(int) * 10);

    for (int i = 0; i < 5; ++i) {
        pointer[i] = 42;
    }

    printf("\n\nPrinting with malloc again:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d, ", pointer[i]);
    }

    pointer = realloc(pointer, 0);
    return 0;
}