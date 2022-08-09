#include <stdio.h>
#include <stdlib.h>
#include "../inc/encoder.h"
#include "../inc/utils.h"
#include "../inc/dict.h"
#include "../inc/list.h"
#include "../inc/tree.h"
#include "../inc/stack.h"

void compress(FILE *fpi) {
    printf("compression...\n");

    FILE *dict_w, *dict_r;

    List list = create_huffman_list(fpi);
    Tree *tree = h_tree(list);
    Stack *stack = NULL;

    dict_w = fopen("dict", "w");
    create_dict(tree, &stack, dict_w);
    fclose(dict_w);

    rewind(fpi);

    dict_r = fopen("dict", "r");
    encode(fpi, dict_r);
    fclose(dict_r);

    clear_tree(tree);
    clear_list(list);

    printf("fin\n");

}

void encode(FILE *fpi, FILE *dict) {
    FILE *fpo = fopen("output.txt", "w");

    char letter;
    int done = 0;

    EncodeList *list = create_encode_list(dict);
    EncodeList *curr = list;

    while ((letter = fgetc(fpi)) != EOF) {
        while (curr || done == 0) {
            if (curr->letter == letter) {
                fputs(curr->value, fpo);
                done = 1;
            }
            curr = curr->next;
        }
        curr = list;
    }
    fclose(fpo);
}

char *get_char(FILE *dict) {

    char *tab = malloc(40 * sizeof(char));

    fscanf(dict, "%s", tab);

    return tab;
}

EncodeList *create_encode_list(FILE *dict) {
    char letter;

    if ((letter = fgetc(dict)) == EOF) return NULL;

    EncodeList *list = malloc(sizeof(EncodeList));
    list->letter = letter;

    letter = fgetc(dict);
    fseek(dict, 2, SEEK_CUR);

    list->value = get_char(dict);


    letter = fgetc(dict);

    list->next = create_encode_list(dict);

    return list;
}