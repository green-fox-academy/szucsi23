#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main()
{
    int num;
    FILE *file;
    file = fopen("MyFile.txt", "r");
    char buffer[30];

    while (fgets(buffer, 30, file) != NULL) {
        fprintf(stdout, "%s", buffer);
    }

    fclose(file);

    return 0;
}