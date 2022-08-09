#include <stdio.h>
#include <stdlib.h>
#include "../inc/encoder.h"
#include <math.h>

int main(void) {
    FILE* input = fopen("test/Alice.txt","r");
    compress(input);
    fclose(input);

    return 0;
}