//
// Created by hun46 on 2019. 05. 20..
//

#ifndef IMPLEMENTED_VECTOR_CLASS_VECTOR_H
#define IMPLEMENTED_VECTOR_CLASS_VECTOR_H

typedef struct {
    void** _data;
    int _capacity;
    int _size;
} vector_t;

//vector manipulators
void vector_init(vector_t*);
void vector_delete(vector_t*, int);
void vector_free(vector_t*);
void vector_shuffle(vector_t*);

//information

int vector_size(vector_t*);
int vector_capacity(vector_t*);
int vector_available(vector_t *);
void *vector_get(vector_t*, int);
int vector_is_empty(vector_t*);

//element manipulators
void vector_push_back(vector_t*, void*);
void vector_insert(vector_t*, int, void*);
void vector_set(vector_t*, int, void*);
int vector_search(vector_t*, void*);


#endif //IMPLEMENTED_VECTOR_CLASS_VECTOR_H
