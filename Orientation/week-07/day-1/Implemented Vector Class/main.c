#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Vector.h"

typedef struct {
    int a;
    double b;
} teststruct;

teststruct init (teststruct t);

int main()
{
    srand (time(NULL));

    vector v;
    vector_init(&v);
    vector_push_back(&v, "1");
    vector_push_back(&v, "2");
    vector_push_back(&v, "3");
    vector_push_back(&v, "4");
    vector_push_back(&v, "5");
    vector_push_back(&v, "6");
    vector_push_back(&v, "7");
    vector_push_back(&v, "8");
    vector_push_back(&v, "9");
    vector_push_back(&v, "10");

    printf("\nfirst round:\n");
    for (int i = 0; i < vector_size(&v); i++) {
        printf("%s\n", vector_get(&v, i));
    }

    vector_shuffle(&v);

    printf("\nsecond round:\n");
    for (int i = 0; i < vector_size(&v); i++) {
        printf("%s\n", vector_get(&v, i));
    }

    vector_free(&v);
    return 0;
}

teststruct init(teststruct t)
{
    t.a = rand() % 10;
    t.b = (rand() % 100) / 10;
    return t;
}