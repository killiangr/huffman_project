#include <stdio.h>
#include <stdlib.h>
#include "../inc/dict.h"
#include "../inc/list.h"
#include "../inc/stack.h"

void create_dict(Tree *tree, Stack **stack, FILE *dict) {
    if (tree) {
        if (tree->left) {
            if (tree->left->letter != 0) {
                *stack = push(*stack, '0');

                fprintf(dict, "%c > ", tree->left->letter);

                stack2dict(*stack, dict);
                fputc('\n', dict);

                create_dict(tree->left, stack, dict);
            } else {
                *stack = push(*stack, '0');
                create_dict(tree->left, stack, dict);
            }
            *stack = stack_pop(*stack);
        }

        if (tree->right) {
            if (tree->right->letter != 0) {
                *stack = push(*stack, '1');

                fprintf(dict, "%c > ", tree->right->letter);

                stack2dict(*stack, dict);
                fputc('\n', dict);

                create_dict(tree->right, stack, dict);
            } else {
                *stack = push(*stack, '1');
                create_dict(tree->right, stack, dict);
            }
            *stack = stack_pop(*stack);
        }
    }
}


void stack2dict(Stack *stack, FILE *dict) {
    if (stack) {
        stack2dict(stack->next, dict);
        fputc(stack->letter, dict);
    }
}