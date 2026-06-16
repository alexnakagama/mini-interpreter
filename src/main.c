#include "vector/vector.h"

#include <stddef.h>
#include <stdio.h>

int main(void) {
    Vector vec;

    vec_init(&vec);

    vec_push(&vec, 15);
    vec_push(&vec, 29);
    vec_push(&vec, 76);

    for (size_t i = 0; i < vec.len; i++) {
        printf("%d\n", vec.items[i]);
    }

    vec_free(&vec);

    return 0;
}
