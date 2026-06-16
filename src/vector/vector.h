#include <cstddef>
#include <stddef.h>

typedef struct Vector {
    int *items;
    size_t len;
    size_t cap;
} Vector;

void vector_init(Vector *vec);
void vector_push(Vector *vec, int value);
int vector_get(Vector *vec, size_t index);
void vector_free(Vector *vec);
