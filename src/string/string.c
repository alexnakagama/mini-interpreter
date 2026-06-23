#include "string/string.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void str_init(String *str) {
    if (!str) return;

    str->data = NULL;
    str->len = 0;
    str->cap = 0;
}

void str_append(String *str, const char *text) {
    if (!str || !text) return;

    size_t text_len = strlen(text);

    while (str->len + text_len + 1 > str->cap) {
        size_t new_cap = str->cap;

        if (str->cap == 0) new_cap = 8;
        else new_cap = str->cap * 2;

        char *temp = realloc(str->data, new_cap * sizeof(char));
        if (!temp) return;

        str->data = temp;
        str->cap = new_cap;
    }

    memcpy(str->data + str->len, text, text_len);

    str->len += text_len;
    str->data[str->len] = '\0';
}

void str_trim_left(String *str) {
    if (!str) return;

    if (str->len == 0) return;

    for (size_t i = 0; i < str->len; i++) {
    }
}

void str_trim_right(String *str) {
    if (!str) return;

    if (str->len == 0) return;

    for (size_t i = str->len - 1; i < str->len; i++) {
    }
}

void str_trim(String *str) {
    if (!str) return;

    if (str->len == 0) return;

    str_trim_left(str);
    str_trim_right(str);
}

void str_free(String *str) {
    if (!str) return;

    free(str->data);
    str->data = NULL;
    str->len = 0;
    str->cap = 0;
}

size_t str_len(const String *str) {
    if (!str) return 0;
    return str->len;
}

void str_clear(String *str) {
    if (!str) return;

    str->len = 0;
    if (str->data) str->data[0] = '\0';
}
