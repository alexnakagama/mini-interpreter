#include "string/string.h"

#include <stddef.h>
#include <stdlib.h>

String *str_init(String *str) {
    if (!str) {
        return NULL;
    }

    str->data = NULL;
    str->len = 0;
    str->cap = 0;

    return str;
}

void str_append(String *str, const char *text) {

}

void str_free(String *str) {
    if (!str) {
        return;
    }

    free(str->data);
    str->data = NULL;
    str->len = 0;
    str->cap = 0;
}
