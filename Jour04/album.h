#ifndef PRINT_ALBUM_H_
#define PRINT_ALBUM_H_

typedef struct album {
    char *artist;
    char *title;
    int year;
} t_album;

//void print_album(struct album *album);
void print_album(t_album *album);

//struct album *realloc_album(struct album *albums, int size, int new_size);
t_album *realloc_album(t_album *albums, int size, int new_size);

#endif