int my_strcmp(char *s1, char *s2) {
//    while (*s1 != '\0' && *s2 != '\0') {
//        if (*s1 > *s2) {
//            return 1;
//        } else if (*s1 < *s2) {
//            return -1;
//        }
//        s1++;
//        s2++;
//    }
//
//    if (*s1 != '\0') {
//        return 1;
//    } else if (*s2 != '\0') {
//        return -1;
//    } else {
//        return 0;
//    }

    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    int result = *s1 - *s2;
    if (result > 0) {
        return 1;
    } else if (result < 0) {
        return -1;
    } else {
        return 0;
    }
}
