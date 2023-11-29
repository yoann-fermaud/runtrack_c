int my_strcmp(char *str1, char *str2) {
//    while (*str1 != '\0' && *str2 != '\0') {
//        if (*str1 > *str2) {
//            return 1;
//        } else if (*str1 < *str2) {
//            return -1;
//        }
//        str1++;
//        str2++;
//    }
//    return 0;

    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    int result = *str1 - *str2;
    if (result > 0) {
        return 1;
    } else if (result < 0) {
        return -1;
    } else {
        return 0;
    }
}
