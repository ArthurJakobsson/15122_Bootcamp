#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib/contracts.h"
#include "lib/xalloc.h"

/**
 * ex2-bad.c
 * Example (2) practicing print statement debugging (student)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * Loosely based on the game fizzbuzz.
 *
 * This is a BUGGY implementation.
 *
 * @author Arthur Jakobsson <ajakobss@andrew.cmu.edu>
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */

/*
 * ---------------------------------------------------------------------------
 *                 SHORT HELPER FUNCTIONS (Defined in full below)
 * ---------------------------------------------------------------------------
 */

/**
 * this function checks if two arrays are equal by looking at each element
 * takes in: A - array of ints; B - array of ints; 
 *           len_A of array A; len_B of array B
 * returns: whether A and B are the same array
 * THIS IS A CORRECT FUNCTION!
 */
bool arrs_equal(int *A, int *B, int len_A, int len_B);

/*
 * ---------------------------------------------------------------------------
 *                                   BUGS!
 * ---------------------------------------------------------------------------
 */

/**
 * this function applys fizzedbuzzed rules onto given array A of length len
 * takes in: A - int array; len - of array
 * TODO: fix the bugs in this function
 */
void fizzed_and_buzzed(int *A, int len)
{
    for (int i = 0; i < len; i+=2)
    {
        if ((A[i] & 0x1) != 0)
        {
            A[i] = 0;
        }
        else if (A[i] % 7 == 0)
        {
            A[i] = 1;
        }
        else if ((A[i] & 0x1) != 0 && (A[i] % 7 == 0))
        {
            A[i] = -1;
        }
    }
}

/*
 * ---------------------------------------------------------------------------
 *                                Test Cases
 * ---------------------------------------------------------------------------
 */

int main()
{
    int *A = xcalloc(sizeof(int), 8);
    A[0] = 4;
    A[1] = 7;
    A[2] = 2;
    A[3] = 14;
    A[4] = 28;
    A[5] = 5;
    A[6] = 7;
    A[7] = 8;

    fizzed_and_buzzed(A, 8);

    int *A_res = xcalloc(sizeof(int), 8); 
    A_res[0] = 4;
    A_res[1] = 1;
    A_res[2] = 2;
    A_res[3] = -1;
    A_res[4] = 28;
    A_res[5] = 5;
    A_res[6] = 7;
    A_res[7] = 0;
    
    assert(arrs_equal(A, A_res, 8, 8));

    int *B = xcalloc(sizeof(int), 7); 
    B[0] = 7;
    B[1] = 1;
    B[2] = 0;
    B[3] = 24;
    B[4] = 6;
    B[5] = 5;
    B[6] = 12;

    fizzed_and_buzzed(B, 7);

    int *B_res = xcalloc(sizeof(int), 7);
    B_res[0] = 7;
    B_res[1] = 1;
    B_res[2] = 0;
    B_res[3] = 0;
    B_res[4] = 6;
    B_res[5] = 5;
    B_res[6] = 12;

    assert(arrs_equal(B, B_res, 7, 7));

    free(A);
    free(A_res);
    free(B); 
    free(B_res);

    printf("All tests passed! \n");
    return 0;
}


/*
 * ---------------------------------------------------------------------------
 *                 DON'T WORRY ABOUT ANYTHING BELOW HERE
 * ---------------------------------------------------------------------------
 */

/**
 * this function checks if two arrays are equal by looking at each element
 * takes in: A - array of ints; B - array of ints; 
 *           len_A of array A; len_B of array B
 * returns: whether A and B are the same array
 * THIS IS A CORRECT FUNCTION!
 */
bool arrs_equal(int *A, int *B, int len_A, int len_B)
{
    if (len_A != len_B) return false;
    for (int i = 0; i < len_A; i++)
    {
        if (A[i] != B[i]) return false;
    }
    return true;
}
