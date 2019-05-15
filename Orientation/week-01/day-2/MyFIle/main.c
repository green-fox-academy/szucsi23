#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void write_to_file(char *path, char *word, int number);

int main()
{
    int num;
    FILE *file;
    file = fopen("MyFile.txt", "r");
    char buffer[30];

    if (file == NULL) {
        printf("Unable to open file");
    } else {
        while (fgets(buffer, 30, file) != NULL) {
            fprintf(stdout, "%s", buffer);
        }
    }
    fclose(file);

    char path[] = "second_file.txt";
    char word[] = "word";
    write_to_file(path, word, 5);

    return 0;
}

void write_to_file(char *path, char *word, int number)
{
    FILE *file;
    file = fopen(path, "w");
    if (file == NULL) {
        printf("Unable to open file");
    } else {
        while(number > 0){
            fprintf(file, word);
            fprintf(file, " ");
            number--;
        }
    }
    fclose(file);
}

