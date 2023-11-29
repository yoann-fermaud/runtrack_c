#include "malloc.h"

char **array_clone(char **strs, int n) {
    char **cloned = (char **) malloc(sizeof(char *) * (n + 1));

    int i;
    for (i = 0; i < n && strs[i] != NULL; i++) {
        int length = 0;
        while (strs[i][length] != '\0') {
            length++;
        }
        cloned[i] = (char *) malloc(sizeof(char) * (length + 1));
        for (int j = 0; j < length; j++) {
            cloned[i][j] = strs[i][j];
        }
        cloned[i][length] = '\0';
    }

    cloned[i] = NULL;
    return cloned;
}
