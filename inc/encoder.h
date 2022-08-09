//
// Created by romain on 07/12/2020.
//
/*****************************************************************//**
 * \file encoder.h.
 *  \brief Encode the text file from the "dict" module and insert it in the "test" folder.
 * \author Dylan Mouheb and his group
 * \date   December 2020 *********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "dict.h"
#include "utils.h"

#ifndef INC_HUFFMAN_ENCODER_H
#define INC_HUFFMAN_ENCODER_H

/**
 * \typedef struct EncodeList
 * \ brief structur composed of 3 elements: letter (to store a character) , *value (store the specific value of a character) .
 * *next (the next element).
 */

typedef struct EncodeList {
    char letter;
    char *value;
    struct EncodeList *next;
} EncodeList;

//////////////////////////////////////////////////////////////
/**
* \brief 
* void compress: take as a parameter: (FILE *fpi) --> compressed from of the character \n
* encode:  take as a parameter:(Stack *stack, FILE *dict) --> the function that calls all the others for encoding \n.
* char *get_char: take as a parameter: (FILE *dict) --> return a character \n.
* EncodeList* create_encode_list: take as a parameter: (FILE* dict)\n.
* \n Example :
* \code{.c}
* \encode
* \return EncodeList* create_encode_list(FILE* dict): the list of characters to encode
* \return char *get_char(FILE *dict): the resulting character
*/

void compress(FILE *fpi);

void encode(FILE *fpi, FILE *dict);

char *get_char(FILE *dict);

EncodeList* create_encode_list(FILE* dict);

#endif //INC_HUFFMAN_ENCODER_H
