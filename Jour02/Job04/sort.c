#include "stdlib.h"

int my_strcmp(char *s1, char *s2);

void swap(char **a, char **b);

char **sort(char **strs) {
    int length = 0;
    while (strs[length] != NULL) {
        length++;
    }
    int i = 0;
    while (strs[i] != NULL) {
        int j = i + 1;
        while (strs[j] != NULL) {
            if (my_strcmp(strs[i], strs[j]) > 0) {
                swap(&strs[i], &strs[j]);
            }
            j++;
        }
        i++;
    }
    return strs;
}

#include "stdio.h"
int main() {
    char *strs[] = {"c", "b", "a", NULL};
    char **sorted = sort(strs);
    int i = 0;
    while (sorted[i] != NULL) {
        printf("%s\n", sorted[i]);
        i++;
    }
    return 0;
}