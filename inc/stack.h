//
// Created by romain on 07/12/2020.
//
/*****************************************************************//**
 * \file dict.h.
 *  \brief
 *  this module permet de gérer les stacks \n.
 *  this fonctions are use in encoder and dict.
 *  * \author Nicolas Gamberini and his group
 * \date   December 2020 *********************************************************************/
#include <stdlib.h>
#include <stdio.h>

#ifndef INC_HUFFMAN_STACK_H
#define INC_HUFFMAN_STACK_H
/**
 * \typedef struct Stack
 * \ brief structur composed of 2 elements: letter, *next \n.
 * cette structure est la base de la liste qui stock temporairement les suite de lettre.
 */
typedef struct Stack {
    char letter;
    struct Stack *next;
} Stack;

//////////////////////////////////////////////////////////////
/**
* \brief
* create_dict: take as a parameter: char letter \n.
* push:  take as a parameter: Stack *stack, char letter \n.
* stack_pop:  take as a parameter: Stack *stack \n.
*
* \return create_stack --> initializes a new stack with the parameter value
* \return push --> add a stack a list of stack for a letter
* \return stack_pop --> free the stack
*/


Stack *create_stack(char letter);

Stack *push(Stack *stack, char letter);

Stack *stack_pop(Stack *stack);

#endif //INC_HUFFMAN_STACK_H
