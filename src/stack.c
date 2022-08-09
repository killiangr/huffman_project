#include "../inc/stack.h"

Stack *create_stack(char letter) {
    Stack *stack = malloc(sizeof(Stack));
    stack->letter = letter;
    stack->next = NULL;

    return stack;
}

Stack *push(Stack *stack, char letter) {

    if (!stack) return create_stack(letter);

    else {
        Stack *new_stack = create_stack(letter);
        new_stack->next = stack;
        return new_stack;
    }
}

Stack *stack_pop(Stack *stack) {
    if (!stack) return stack;

    else {
        Stack *next = stack->next ? stack->next : NULL;
        free(stack);
        return next;
    }
}