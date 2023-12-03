#include "unistd.h"
#include "stdbool.h"
#include "malloc.h"

int atoi(char *str);
char *itoa(int nbr);
int intLength(int nbr);
int factorial(int nbr);

int main(int argc,char **argv) {
    if (argc != 2) {
        return 1;
    }

    int result = factorial(atoi(argv[1]));
    char *str = itoa(result);

    write(1, str, intLength(result));
    write(1, "\n", 1);
    free(str);

    return 0;
}

int atoi(char *str) {
    int result = 0;
    bool negative = false;

    while (*str != '\0') {
        if (str[0] == '-') {
            negative = true;
            str++;
        }

        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
            str++;
        } else {
            return 0;
        }
    }

    return negative ? -result : result;
}

char *itoa(int nbr) {
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

    str[nbrSize] = '\0';
    while (nbr != 0) {
        str[nbrSize - 1] = '0' + (nbr % 10);
        nbr = nbr / 10;
        nbrSize--;
    }

    return str;
}

int intLength(int nbr) {
    int result = 0;

    while (nbr != 0) {
        nbr = nbr / 10;
        result++;
    }

    return result;
}

int factorial(int nbr) {
    int result = 1;

    while (nbr > 0) {
        result = result * nbr;
        nbr--;
    }

    return result;
}
