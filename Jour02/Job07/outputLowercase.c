#include "unistd.h"

void toLowercase(char *str) {
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 32;
        }
        str++;
    }
}

int strLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main(int argc, char **argv) {
    int  i = 1;
    while (i < argc) {
        toLowercase(argv[i]);
        write(1, argv[i], strLength(argv[i]));
        write(1, "\n", 1);
        i++;
    }
    return 0;
}