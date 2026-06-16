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

    if (!index) {
        return -1;
    }

    return vec->items[index];
}

void vec_free(Vector *vec) {
    if (!vec) {
        return;
    }

    free(vec);
}
