#pragma once

#include <stddef.h>

typedef struct Vector {
    int *items;
    size_t len;
    size_t cap;
} Vector;

Vector *vec_init(Vector *vec);
void vec_push(Vector *vec, int value);
int vec_get(Vector *vec, size_t index);
void vec_pop(Vector *vec, size_t index);
void vec_free(Vector *vec);

