#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <stdbool.h>
#include "lib/xalloc.h"
#include "lib/ex4-helper.h"

/**
 * ex4.c
 * Example (4) practicing valgrind debugging (student)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * Based on Pascal's Triangle on Leetcode
 * https://tinyurl.com/PascalTriangleAnswer
 *
 * This is a BUGGY implementation.
 *
 * @author Arthur Jakobsson <ajakobss@andrew.cmu.edu>
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */

/*
 * ---------------------------------------------------------------------------
 *                                 STRUCT
 * ---------------------------------------------------------------------------
 */

/** 
 * struct of triangle node (containing int array data & size) 
 * note: defined in header file 
 */
// typedef struct triangle_header {
//     int **data;
//     long size;
// } triangle;

/*
 * ---------------------------------------------------------------------------
 *                          SHORT HELPER FUNCTIONS
 * ---------------------------------------------------------------------------
 */

/**
 * this function prints out triangle, given number of rows
 * takes in: tri - 2d array representing triangle; num_rows - number of rows
 * THIS IS A CORRECT FUNCTION!
*/
void print_triangle(int **tri, int num_rows);

/*
 * ---------------------------------------------------------------------------
 *                                   BUGS!
 * ---------------------------------------------------------------------------
 */

/**
 * this function generates a pascal's triangle, given a struct and number of rows
 * takes in: my_tri - triangle to create; num_rows - number of rows in triangle
 * returns: triangle generated
 * TODO: fix the bugs in this function
 */
triangle *generate(triangle *my_tri, int num_rows)
{
    int **tri_data = xcalloc(num_rows, sizeof(int*));

    my_tri->data = tri_data;
    my_tri->size = num_rows;

    for (int i = 0; i < num_rows; i++)
    {
        tri_data[i] = xmalloc(i * sizeof(int));
        tri_data[i][0] = 1;  // first element of each row is always 1

        for (int j = 1; j < i; j++)
        {
            // calculate each element of the current row
            tri_data[i][j] = tri_data[i-1][j-1] + tri_data[i-1][j];
        }
        tri_data[i][i] = 1;  // last element of each row is always 1
    }
    return my_tri;
}

/**
 * this function creates a pascal's triangle, prints it, and frees all alloc'ed memory
 * TODO: fix the bugs in this function
 */
int main()
{
    int num_rows = 7;

    triangle *my_triangle = xmalloc(sizeof(triangle));

    my_triangle = generate(my_triangle, num_rows);
    print_triangle(my_triangle->data, num_rows); // just prints the triangle

    free(my_triangle->size);
    for (int i = 0; i < num_rows - 1; i++)
    {
        free(my_triangle->data[i]);
    }
    free(my_triangle);
    return 0;
}
