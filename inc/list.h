//
// Created by Dylan on 07/12/2020.
//
/*****************************************************************//**
 * \file   list.h
 * \brief  allows to have the number of occurrences in a file
 * 
 * \author Dylan Mouheb and his group 
 * \date   December 2020 
 *********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

#ifndef INC_HUFFMAN_LIST_H
#define INC_HUFFMAN_LIST_H

/** 
 * \typedef struct Node
 * \brief has 3 elements: occ(numbr of occurrences) , letter (the character), and a structure pointer (*next).
 */
typedef struct Node {
    int occ;
    char letter;
    struct Node *next;
} Node, *List;


/**
 *\brief functions which will allow you to count the occurrence in the "Alice" file\n.
 * \n Example :
 * \code{.c}
 * \endcode
 * \return the list once the element has been added (List append)
 * \return the last element in the list before it is removed (List pop)
 * \return the Huffman list with letters and thei occurrences
 */
List create_huffman_list(FILE *fpi);

List append(List list, char letter, int occ);

List pop(List list);

void clear_list(List list);

#endif //INC_HUFFMAN_LIST_H
