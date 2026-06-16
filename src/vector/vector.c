#include "vector.h"

#include <stddef.h>
#include <stdlib.h>

Vector *vec_init(Vector *vec) {
    if (!vec) {
        return NULL;
    }

    vec->items = NULL;
    vec->cap = 0;
    vec->len = 0;

    return vec;
}

/*
    vec_push receives a pointer to the vector and a value we want to insert
    if the vector is full (vec->len == vec-cap) we need more memory, we create a temporal var
    when the vector is recently created we put an initial capacity of 8
    in the other case we duplicate the capacity of the vector new_cap = vec->cap * 2
    with realloc we ask more memory
    we update the pointer and the capacity vec->items = temp / vec->cap = new_cap
    then insert the elements with vec->items[vec-len] and increase the len with ++
*/
void vec_push(Vector *vec, int value) {
    if (!vec) {
        return;
    }

    if (vec->len == vec->cap) {
        size_t new_cap = vec->cap;
        if (vec->cap == 0) {
            new_cap = 8;
        } else {
            new_cap = vec->cap * 2;
        }

        int *temp = realloc(vec->items, sizeof(int) * new_cap);
        if (!temp) {
            return;
        }

        vec->items = temp;
        vec->cap = new_cap;
    }

    vec->items[vec->len] = value;
    vec->len++;
}

int vec_get(Vector *vec, size_t index) {
    if (!vec) {
        return -1;
    }

    if (index >= vec->len) {
        return -1;
    }

    return vec->items[index];
}

void vec_pop(Vector *vec, size_t index) {
    
}

void vec_free(Vector *vec) {
    if (!vec) {
        return;
    }

    free(vec->items);
    vec->items = NULL;
    vec->len = 0;
    vec->cap = 0;
}
