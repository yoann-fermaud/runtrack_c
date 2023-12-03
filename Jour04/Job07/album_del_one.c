#include "unistd.h"
#include "malloc.h"
#include "../album_list.h"

void album_del_one(t_album_list **list, t_album_list *album) {
    if (list == NULL || *list == NULL || album == NULL) {
        return;
    }

    if (*list == album) {
        *list = album->next;
        free(album);
        return;
    }

    t_album_list *prev = *list;
    t_album_list *curr = (*list)->next;

    while (curr != NULL) {
        if (curr == album) {
            prev->next = curr->next;
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}