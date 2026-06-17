#include "string/string.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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
    if (!str || !text) {
        return;
    }

    size_t text_len = strlen(text);

    while (str->len + text_len + 1 > str->cap) {
        size_t new_cap = str->cap;
        if (str->cap == 0) {
            new_cap = 8;
        } else {
            new_cap = str->cap * 2;
        }

        char *temp = realloc(str->data, new_cap);
        if (!temp) {
            return;
        }

        str->data = temp;
        str->cap = new_cap;
    }

    memcpy(
        str->data + str->len,
        text,
        text_len
    );

    str->len += text_len;
    str->data[str->len] = '\0';
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
