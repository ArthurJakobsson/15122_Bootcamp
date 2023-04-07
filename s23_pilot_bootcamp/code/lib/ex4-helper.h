#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <stdbool.h>
#include "xalloc.h"

typedef struct triangle_header {
    int **data;
    long size;
} triangle;

/**
 * this function prints out triangle, given number of rows
 * takes in: tri - 2d array representing triangle; num_rows - number of rows
 * THIS IS A CORRECT FUNCTION!
*/
void print_triangle(int **tri, int num_rows); 
