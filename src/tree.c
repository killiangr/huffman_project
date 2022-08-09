#include "../inc/tree.h"

Tree *init_tree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->letter = '\0';
    tree->occ = 0;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Tree *create_tree(Tree *left, Tree *right, int weight) {
    Tree *tree = create_node(0, weight);

    tree->left = left;
    tree->right = right;

    if (left) left->parent = tree;
    if (right) right->parent = tree;

    return tree;
}

Tree *h_tree(List list) {
    List curr = list;

    Tree *tree, *left, *right;

    int occ;
    int weight;
    char letter;

    TreeList *node_list = NULL;

    while (curr != NULL) {
        occ = curr->occ;
        letter = curr->letter;
        curr = pop(curr);

        left = create_node(letter, occ);
        insert_node(&node_list, left);
    }
    while (TreeList_len(node_list) != 1) {
        left = TreeList_min(&node_list);
        right = TreeList_min(&node_list);
        weight = left->occ + right->occ;

        tree = create_tree(left, right, weight);
        insert_node(&node_list, tree);
    }
    tree = TreeList_min(&node_list);


    return tree;
}

Tree *create_node(char letter, int occ) {
    Tree *tree = malloc(sizeof(*tree));

    tree->occ = occ;
    tree->letter = letter;

    tree->left = NULL;
    tree->right = NULL;
    tree->parent = NULL;

    return tree;
}

void insert_node(TreeList **list, Tree *tree) {

    TreeList *el = malloc(sizeof(*el));
    el->node = tree;
    el->next = NULL;

    if (!(*list)) *list = el;
    else {
        TreeList *curr = *list;

        while (curr->next)
            curr = curr->next;

        curr->next = el;
    }
}

int compare_node(Tree *node1, Tree *node2) {
    if (node1 == node2) return 1;
    if (!node1 || !node2) return 0;
    return (
            (node1->occ == node2->occ)
            && (node1->letter == node2->letter)
            && compare_node(node1->left, node2->left)
            && compare_node(node1->right, node2->right)
    );
}

void delete_node(TreeList **list, Tree *tree) {
    if (*list && tree) {
        if (compare_node((*list)->node, tree) == 1) {
            TreeList *tmp = *list;
            *list = (*list)->next;
            free(tmp);

        } else delete_node(&((*list)->next), tree);
    }
}

Tree *TreeList_min(TreeList **list) {
    if (*list) {
        int min;

        TreeList *tmp = *list;
        Tree *curr = NULL;

        min = (*list)->node->occ;

        while (tmp) {
            if (tmp->node->occ <= min) {
                min = tmp->node->occ;
                curr = tmp->node;
            }
            tmp = tmp->next;
        }
        delete_node(list, curr);

        return curr;
    } else return NULL;
}

int TreeList_len(TreeList *list) {
    int i = 0;

    if (!list) return i;

    while (list) {
        i++;
        list = list->next;
    }

    return i;
}

void clear_tree(Tree *tree) {
    if (!tree) return;

    clear_tree(tree->left);
    clear_tree(tree->right);

    free(tree);
}