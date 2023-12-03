#include "malloc.h"
#include "../album_list.h"

int myStrlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char *myStrcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

t_album_list *create_album(char *artist, char *title, int year) {
    t_album_list *album = (t_album_list *) malloc(sizeof(t_album_list));
    if (album == NULL) {
        return NULL;
    }

    album->artist = (char *) malloc(sizeof(char) * (myStrlen(artist) + 1));
    if (album->artist == NULL) {
        free(album->artist);
        free(album);
        return NULL;
    }
    myStrcpy(album->artist, artist);

    album->title = (char *) malloc(sizeof(char) * (myStrlen(title) + 1));
    if (album->title == NULL) {
        free(album->title);
        free(album);
        return NULL;
    }
    myStrcpy(album->title, title);

    album->year = year;
    album->next = NULL;

    return album;
}
