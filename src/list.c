#include "../inc/list.h"

List create_huffman_list(FILE *fpi) {
    if (!fpi) return NULL;

    char letter;
    int exist = 0;

    List list = malloc(sizeof(*list));
    list->letter = fgetc(fpi);
    list->occ = 1;
    list->next = NULL;

    List curr = list;

    while ((letter = fgetc(fpi)) != EOF) {
        while (curr) {
            if (curr->letter == letter) {
                curr->occ++;
                exist = 1;
            }
            curr = curr->next;
        }
        if (exist == 0) list = append(list, letter, 1);

        exist = 0;
        curr = list;
    }
    return list;
}

List append(List list, char letter, int occ) {
    List new = malloc(sizeof(*new));

    new->letter = letter;
    new->occ = occ;

    if (!list) new->next = NULL;
    else new->next = list;

    return new;

}

List pop(List list) {
    if (!list) return NULL;

    List el = malloc(sizeof(*el));

    el = list->next;
    free(list);

    return el;
}

void clear_list(List list) {
    if (!list) return;

    clear_list(list->next);

    free(list);
}