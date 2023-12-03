#include "unistd.h"
#include "../album_list.h"

void push_front_album(t_album_list **list, t_album_list *album) {
    if (list == NULL) {
        return;
    }

    album->next = *list;
    *list = album;
}
