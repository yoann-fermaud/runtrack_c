#include "malloc.h"

char *trim(char *src) {
    if (src == NULL) {
        return NULL;
    }

    int length = 0;
    int start = 0;
    int end = 0;

    while (src[length] != '\0') {
        length++;
    }

    while (src[start] == ' ' || src[start] == '\t' || src[start] == '\n') {
        start++;
    }

    while (src[length - 1] == ' ' || src[length - 1] == '\t' || src[length - 1] == '\n') {
        length--;
    }

    char *trimmed = (char *)malloc(sizeof(char) * (length - start + 1));

    if (trimmed != NULL) {
        for (int i = start; i < length; i++) {
            trimmed[end] = src[i];
            end++;
        }
        trimmed[end] = '\0';
    }

    return trimmed;
}
