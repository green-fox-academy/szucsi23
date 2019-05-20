//
// Created by hun46 on 2019. 05. 20..
//

#ifndef IMPLEMENTED_VECTOR_CLASS_VECTOR_H
#define IMPLEMENTED_VECTOR_CLASS_VECTOR_H

typedef struct {
    void** _data;
    int _capacity;
    int _size;
} vector;

//vector manipulators
void vector_init(vector*);
void vector_delete(vector*, int);
void vector_free(vector*);
void vector_shuffle(vector*);

//information
int vector_size(vector*);
int vector_capacity(vector*);
int vector_available(vector *);
void *vector_get(vector*, int);
int vector_is_empty(vector*);

//element manipulators
void vector_push_back(vector*, void*);
void vector_insert(vector*, int, void*);
void vector_set(vector*, int, void*);
int vector_search(vector*, void*);


#endif //IMPLEMENTED_VECTOR_CLASS_VECTOR_H
