#include <stdio.h>
#include <string.h>

int lenght(char string[]);

int are_the_same(char string1[], char string2[]);

int find_it(char long_string[], char character);

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char name[100];

    printf("What's your name?\n");
    scanf("%s", name);
    printf("That's %d characters long.\n", lenght(name));

    //------------------------------------------------------------------------------------------------------------------
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char string1[100];
    char string2[100];
    printf("Give me two strings\n");
    scanf("%s %s", string1, string2);

    if (are_the_same(string1, string2)) {
        printf("These strings are equal.\n");
    } else {
        printf("These strings are not equal.\n");
    }

    //------------------------------------------------------------------------------------------------------------------
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1

    char long_string[100];
    char character;
    printf("Give me one more string and a character!\n");
    scanf("%s %c", long_string, &character);

    if (find_it(long_string, character) == -1) {
        printf("It's nowhere to be found.\n");
    } else {
        printf("It's in the %d'th position.\n", find_it(long_string, character));
    }

    return 0;
}

int lenght(char string[])
{
    int num = 0;

    while(*string != '\0') {
        string++;
        num++;
    }
    return num;
}

int are_the_same(char *string1, char *string2)
{
    if (strlen(string1) != strlen(string2)) return 0;

    while(*string1 != '\0') {

        if(*string1 < 97) *string1 += 32;
        if(*string2 < 97) *string2 += 32;

        if (*string1 != *string2) return 0;
        string1++;
        string2++;
    }
    return 1;
}

int find_it(char *long_string, char character)
{
    for (int i = 0; i < strlen(long_string); ++i) {
        if(long_string[i] == character) return i;
    }
    return -1;
}
