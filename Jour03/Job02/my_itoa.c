#include "malloc.h"

char *my_itoa(int nbr) {
    // 4567 / 10 = 456
    // 456 / 10 = 45
    // 45 / 10 = 4
    // 4 / 10 = 0
    int tmp = nbr;
    int nbrSize = 0;

    while (tmp != 0) {
        tmp = tmp / 10;
        nbrSize++;
    }

    char *str = (char *) malloc(sizeof(char) * (nbrSize + 1));
    if (str == NULL) {
        return NULL;
    }

    // '0' + (4567 % 10) = '0' + 7 = '7'
    // '0' + (456 % 10) = '0' + 6 = '6'
    // '0' + (45 % 10) = '0' + 5 = '5'
    // '0' + (4 % 10) = '0' + 4 = '4'
    // '0' + (0 % 10) = '0' + 0 = '0'
    str[nbrSize] = '\0';
    while (nbr != 0) {
        str[nbrSize - 1] = '0' + (nbr % 10);
        nbr = nbr / 10;
        nbrSize--;
    }

    return str;
}
