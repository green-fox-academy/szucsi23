#include <stdio.h>
#include <string.h>

void slicer (char sentence[]);
void list_poz(char sentence[]);
int distance(char sentence[]);

int main()
{
    // create a function which takes a char array as a parameter,
    // and splits a string to words by space
    // solve the problem with the proper string.h function

    printf("Type in a sentence:\n");
    char string[256];
    gets(string);
    slicer(string);

    //------------------------------------------------------------------------------------------------------------------
    // create a function which takes a char array as a parameter and
    // lists all position where character 'i' is found

    list_poz(string);

    //------------------------------------------------------------------------------------------------------------------
    // create a function which takes a char array as a parameter and
    // returns the distance between the first and last occurance of character 's'

    int dist = distance(string);
    printf("%d", dist);

    return(0);
}

void slicer(char sentence[])
{
    char *p = strtok(sentence, " ");
    while ( p != NULL) {
        puts(p);
        p = strtok(NULL, " ");
    }
}

void list_poz(char *sentence)
{
    for (int i = 0; i < strlen(sentence); ++i) {
        if(sentence[i] == 'i') {
            printf("%d ", i);
        }
    }

}

int distance(char *sentence)
{
    int first = 0;
    int second = 0;
    int flag = 1;
    for (int i = 0; i < strlen(sentence); ++i) {
        if(sentence[i] == 's') {
            if(flag){
                first = i;
                flag = 0;
            }
            second = i;
        }
    }
    return (second - first);
}
