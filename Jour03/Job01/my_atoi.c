#include "stdbool.h"

int my_atoi(char *str) {
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
