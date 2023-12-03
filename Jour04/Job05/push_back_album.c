#include "unistd.h"
#include "../album_list.h"

void push_back_album(t_album_list *list, t_album_list *album) {
    if (list == NULL) {
        return;
    }

    t_album_list *current = list;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = album;
    album->next = NULL;
}
