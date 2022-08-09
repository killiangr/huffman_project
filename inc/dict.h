//
// Created by killian on 07/12/2020.
//
/*****************************************************************//**
 * \file dict.h.
 *  \brief  
This module allows you to create the Huffman dictionary sought for our input file
we get the necessary information (characters, their numbers, position) and 
we will transfer them to a text file "dictionnary".
 */
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stack.h"

#ifndef INC_HUFFMAN_DICT_H
#define INC_HUFFMAN_DICT_H
/**
 * \typedef struct Dict 
 * \ brief structur composed of 4 elements: key, *val, *left, *right.
 */
typedef struct Dict {
    char key;
    char *val;

    struct Dict *left;
    struct Dict *right;
} Dict;

//////////////////////////////////////////////////////////////
/**
* \brief  
* create_dict: take as a parameter: Tree *tree, Stack **P, FILE *dict \n.
* stack2dict:  take as a parameter: Stack *stack, FILE *dict\n.
* \n Example :
* \code{.c}
* \endcode
* \return create_dict --> initializes the dictionary 
* \return stack2dict --> turn the stack into a dictionary
*/

void create_dict(Tree *tree, Stack **P, FILE *dict);

void stack2dict(Stack *stack, FILE *dict);

#endif //INC_HUFFMAN_DICT_H
