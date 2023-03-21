#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @file pascalTriangle.c
 * @brief Code to print Pascal's Triangle for n number of rows
 *
 * 15-122: Introduction to Imperative programming
 *
 * Based on Pascal's Triangle on Leetcode
 * Solution derived from https://tinyurl.com/PascalTriangleAnswer C++ answer
 *
 * Adapted for use in the 15122 C Bootcamp series.
 *
 * This is the NON-buggy implementation.
 *
 * @author Arthur Jakobsson <ajakobss@andrew.cmu.edu>
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */



/*
 * Forward declarations of support functions
 * (Don't worry about this it won't be buggy)
 */
static void print_triangle(int** triangle, int numRows);

typedef struct triangle_header {
    int** data;
    long size;
} triangle;



triangle *generate(triangle *myTri, int numRows) {
    int** triangle = (int**) malloc(numRows * sizeof(int*));
    if(triangle==NULL){ perror("Malloc returned NULL");}
    myTri->data = triangle;
    myTri->size = numRows;
    for(int i = 0; i < numRows; i++) {
        triangle[i] = (int*) malloc( (i) * sizeof(int));
        if(triangle[i]==NULL){ perror("Malloc returned NULL");}
        triangle[i][0] = 1;  // First element of each row is always 1.
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];  // Calculate each element of the current row.
        }
        triangle[i][i] = 1;  // Last element of each row is always 1.
    }
    return myTri;
}

int main() {
    int numRows = 7;

    triangle *myTriangle = (triangle *) malloc(1*sizeof(triangle));
    if(myTriangle==NULL){ perror("Malloc returned NULL");}
    myTriangle = generate(myTriangle, numRows);
    print_triangle(myTriangle->data, numRows); //Just prints the triangle

    free((int *)myTriangle->size);
    for (int i = 1; i < numRows-1; i++) {
        free(myTriangle->data[i]);
    }
    free(myTriangle->data);
    free(myTriangle);
    return 0;
}

/*
 * ---------------------------------------------------------------------------
 *                           SHORT HELPER FUNCTIONS
 * ---------------------------------------------------------------------------
 *
 * Don't worry about this part... it won't be buggy it is just here
 * to help test your implementation
 *
 */


void print_triangle(int** triangle, int numRows) { //just prints the triangle
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}
