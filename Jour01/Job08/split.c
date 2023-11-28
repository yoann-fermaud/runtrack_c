#include "malloc.h"

char *my_strncpy(char *dest, char *src, int n);

char **split(char *src) {
    if (src == NULL) {
        return NULL;
    }

    int inWord = 0;
    int wordCount = 0;
    int srcLength = 0;

    while (*src) {
        if (*src == ' ' || *src == '\t' || *src == '\n') {
            if (inWord) {
                inWord = 0;
            }
        } else {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        }
        srcLength++;
        src++;
    }

    char **tab = (char **) malloc(sizeof(char *) * (wordCount + 1));

    src -= srcLength;
    inWord = 0;
    wordCount = 0;
    int wordLength = 0;

    while (*src) {
        if (*src == ' ' || *src == '\t' || *src == '\n') {
            if (inWord) {
                inWord = 0;
                tab[wordCount] = (char *) malloc(sizeof(char) * (wordLength + 1));
                my_strncpy(tab[wordCount], src - wordLength, wordLength);
                tab[wordCount][wordLength] = '\0';
                wordCount++;
                wordLength = 0;
            }
        } else {
            if (!inWord) {
                inWord = 1;
            }
            wordLength++;
        }
        src++;
    }

    if (inWord) {
        tab[wordCount] = (char *) malloc(sizeof(char) * (wordLength + 1));
        my_strncpy(tab[wordCount], src - wordLength, wordLength);
        tab[wordCount][wordLength] = '\0';
        wordCount++;
    }

    tab[wordCount] = NULL;
    return tab;
}
