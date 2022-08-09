//
// Created by romain on 07/12/2020.
//

#include <stdlib.h>
#include <stdio.h>

#ifndef INC_HUFFMAN_TREE_H
#define INC_HUFFMAN_TREE_H

#include "list.h"

typedef struct Tree {
    int occ;
    char letter;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
} Tree;

typedef struct TreeList {
    Tree *node;
    struct TreeList *next;
} TreeList;

//////////////////////////////////////////////////////////////

Tree *init_tree();

Tree *create_node(char letter, int occ);

Tree *h_tree(List list);

void insert_node(TreeList **list, Tree *tree);

int compare_node(Tree *node1, Tree *node2);

void delete_node(TreeList **list, Tree *tree);

Tree *TreeList_min(TreeList **list);

int TreeList_len(TreeList *list);

void clear_tree(Tree *tree);

#endif //INC_HUFFMAN_TREE_H
