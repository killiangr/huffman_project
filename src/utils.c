#include "../inc/utils.h"
#include "../inc/list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int chars_count(FILE *fpi) {
    int i = 0;
    char character;

    while ((character = fgetc(fpi)) != EOF) i++;

    return i;
}

int bin2int(char *string) {
    return (int) strtol(string, NULL, 2);
}