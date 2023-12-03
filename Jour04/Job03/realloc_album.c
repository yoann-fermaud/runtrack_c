#include "malloc.h"
#include "../album.h"

t_album *realloc_album(t_album *albums, int size, int new_size) {

    t_album *new_albums = (t_album *) malloc(sizeof(t_album) * new_size);
    if (new_albums == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        new_albums[i] = albums[i];
    }

    free(albums);

    return new_albums;
}
