//
// Created by hun46 on 2019. 05. 20..
//

#include "Vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_init(vector *v)
{
    v->_data = NULL;
    v->_capacity = 0;
    v->_size = 0;
}

int vector_size(vector *v)
{
    return v->_size;
}

void vector_push_back(vector *v, void *data)
{
    if (v->_capacity == 0) {
        v->_capacity = 10;
        v->_data = malloc(sizeof(void *) * v->_capacity);
        memset(v->_data, '\0', sizeof(void) * v->_capacity);
    }
    if (v->_capacity == v->_size) {
        v->_capacity *= 2;
        v->_data = realloc(v->_data, sizeof(void *) * v->_capacity);
    }

    v->_data[v->_size] = data;
    v->_size++;
}


void vector_set(vector *v, int index, void *data)
{
    if (index >= v->_size) {
        return;
    }

    v->_data[index] = data;
}

void *vector_get(vector *v, int index)
{
    if (index >= v->_size) {
        return 0;
    }

    return v->_data[index];
}

void vector_delete(vector *v, int index)
{
    if (index >= v->_size) {
        return;
    }

    v->_data[index] = NULL;


    void **newarr = (void **) malloc(sizeof(void *) * v->_size * 2);
    int j = 0;
    for (int i = 0; i < v->_size; i++) {
        if (v->_data[i] != NULL) {
            newarr[j] = v->_data[i];
            j++;
        }
    }

    free(v->_data);

    v->_data = newarr;
    v->_size--;
}

void vector_free(vector *v)
{
    free(v->_data);
}

void vector_insert(vector *v, int index, void *data)
{
    if (v->_capacity == 0) {
        v->_capacity = 10;
        v->_data = malloc(sizeof(void *) * v->_capacity);
        memset(v->_data, '\0', sizeof(void) * v->_capacity);
    }
    if (v->_capacity == v->_size) {
        v->_capacity *= 2;
        v->_data = realloc(v->_data, sizeof(void *) * v->_capacity);
    }

    v->_size++;
    for (int i = v->_size; i > index; --i) {
        v->_data[i] = v->_data[i - 1];

    }
    v->_data[index] = data;
}

int vector_capacity(vector *v)
{
    return v->_capacity;
}

int vector_available(vector *v)
{
    return (v->_capacity - v->_size);
}

int vector_is_empty(vector *v)
{
    return (v->_size > 0);
}

int vector_search(vector *v, void *data)
{
    for (int i = 0; i < v->_size; ++i) {
        if (v->_data[i] == data) {
            return i;
        }
    }
    return -1;
}

void vector_shuffle(vector *v)
{
    int array[v->_size];
    for (int i = 0; i < v->_size; ++i) {
        array[i] = i;
    }
    for (int i = 0; i < v->_size; i++) {
        int j = i + (rand() % (v->_size - i));
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }

    for (int i = 0; i < v->_size; ++i) {
        void *temp = v->_data[i];
        v->_data[i] = v->_data[array[i]];
        v->_data[array[i]] = temp;
    }

}



