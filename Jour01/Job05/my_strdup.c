#include "malloc.h"

int my_strlen(char *str);
char *my_strcpy(char *dest, char *src);

char *my_strdup(char *str) {
    if (str == NULL) {
        return NULL;
    }

    char *duplicate = (char*)malloc(sizeof(char) * (my_strlen(str) + 1));

    if (duplicate != NULL) {
        my_strcpy(duplicate, str);
    }

    return duplicate;
}
