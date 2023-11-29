#include "unistd.h"
#include "malloc.h"

int strLength(char *src) {
    int length = 0;
    while (src[length] != '\0') {
        length++;
    }
    return length;
}

char *strTrim(char *src) {
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

    char *trimmed = (char *) malloc(sizeof(char) * (length - start + 1));

    if (trimmed != NULL) {
        for (int i = start; i < length; i++) {
            trimmed[end] = src[i];
            end++;
        }
        trimmed[end] = '\0';
    }

    return trimmed;
}

int strCmp(char *str0, char *str1) {
    while (*str0 != '\0' && *str1 != '\0' && *str0 == *str1) {
        str0++;
        str1++;
    }

    if (*str0 - *str1 > 0) {
        return 1;
    } else if (*str0 - *str1 < 0) {
        return -1;
    } else {
        return 0;
    }
}

void strSwap(char **str0, char **str1) {
    char *temp = *str0;
    *str0 = *str1;
    *str1 = temp;
}

char **strSort(char **src) {
    int length = 0;
    while (src[length] != NULL) {
        length++;
    }

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strCmp(src[i], src[j]) > 0) {
                strSwap(&src[i], &src[j]);
            }
        }
    }
    return src;
}

int main(int argc, char **argv) {
    char **trimmedArray = (char **) malloc(sizeof(char *) * (argc));
    for (int i = 1; i < argc; i++) {
        trimmedArray[i - 1] = strTrim(argv[i]);
    }

    trimmedArray[argc - 1] = NULL;
    strSort(trimmedArray);

    for (int i = 0; i < argc - 1; i++) {
        write(1, trimmedArray[i], strLength(trimmedArray[i]));
        write(1, " ", 1);
    }
    write(1, "\n", 1);

    for (int i = 0; i < argc - 1; i++) {
        free(trimmedArray[i]);
    }
    free(trimmedArray);

    return 0;
}