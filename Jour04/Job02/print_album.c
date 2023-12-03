#include "unistd.h"
#include "../album.h"

int myStrlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void print_album(t_album *album) {
    write(1, "Artist: ", 8);
    write(1, album->artist, myStrlen(album->artist));
    write(1, "\nTitle: ", 8);
    write(1, album->title, myStrlen(album->title));
    write(1, "\nYear: ", 7);

    char year[5];
    int i = 0;
    while (album->year > 0) {
        year[i] = album->year % 10 + '0';
        album->year /= 10;
        i++;
    }
    while (i > 0) {
        write(1, &year[i - 1], 1);
        i--;
    }
    write(1, "\n", 1);
}
