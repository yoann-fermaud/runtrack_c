#ifndef ALBUM_LIST_H_
#define ALBUM_LIST_H_

/*
 * A linked list of albums.
 */
typedef struct album_list {
    char *artist;
    char *title;
    int year;
    struct album_list *next;
} t_album_list;

void push_back_album(t_album_list *list, t_album_list *album);

void push_front_album(t_album_list **list, t_album_list *album);

void album_del_one(t_album_list **list, t_album_list *album);

#endif