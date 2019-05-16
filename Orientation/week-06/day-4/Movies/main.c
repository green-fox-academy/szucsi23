#include <stdio.h>
#include <stdlib.h>

//In the file you can find the best grossing movies in the format: [Title] [Profit] [Release date]
//Make a function that reads the data and returns a pointer to the data and the size. The function should not use more memory than necessary.
//Print the summed profit grouped by year
//Which was the most successful year in the movie industry?

typedef struct {
    char *title;
    char *profit;
    int year;
} movie_t;

void delete(movie_t);

movie_t *read_from_file(char path[]);

int main()
{
    movie_t *movies = read_from_file("movies.txt");
    return 0;
}

movie_t *read_from_file(char *path)
{
    movie_t *movies;
    int size = sizeof(movies)/ sizeof(movie_t);

    FILE *file;
    file = fopen(path, "r");


    //TODO: tokenek, külön buffer minden adattagnak, dinamikusan beolvas és aztán egyberak, és azt az egyben elemet beletölt a tömbbe.
    movie_t buffer;

}

void delete(movie_t movie)
{
    free(movie.title);
    movie.title = NULL;
    free(movie.profit);
    movie.profit = NULL;
}
