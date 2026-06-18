#pragma once

#include <stddef.h>

typedef struct String {
    char *data;
    size_t len;
    size_t cap;
} String;

void str_init(String *str);
void str_append(String *str, const char *text);
void str_free(String *str);
void str_trim(String *str);
size_t str_len(const String *str);
void str_clear(String *str);

