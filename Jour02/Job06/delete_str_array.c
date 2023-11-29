#include "malloc.h"

void delete_str_array(char ***strs) {
    if (strs == NULL || *strs == NULL) {
        return;
    }

    int i = 0;
    while ((*strs)[i] != NULL) {
        free((*strs)[i]);
        i++;
    }

    free(*strs);
    *strs = NULL;
}
