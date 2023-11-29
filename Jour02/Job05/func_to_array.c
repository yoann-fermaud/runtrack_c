#include "unistd.h"

void func_to_array(char **strs, void (*fun)(char *)) {
    while(*strs != NULL) {
        fun(*strs);
        strs++;
    }
}

void putstr(char *str) {
    while (*str != '\0') {
        write(1, str, 1);
        str++;
    }
}
