#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib/contracts.h"
#include "lib/xalloc.h"

/**
 * @file ex2-correct.c
 * @brief Example (2) practicing print statement debugging (student)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * Loosely based on the game fizzbuzz.
 *
 * This is a CORRECT implementation.
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
 * @brief checks if two arrays are equal by looking at each element
 * THIS IS A CORRECT FUNCTION!
 */
bool arrs_equal(int *A, int *B, int len_A, int len_B);

/*
 * ---------------------------------------------------------------------------
 *                                   BUGS!
 * ---------------------------------------------------------------------------
 */

/**
 * @brief applys fizzedbuzzed rules onto given array A of length len
 * @param A int array
 * @param len of array
 * TODO: fix the bugs in this function
 */
void fizzed_and_buzzed(int *A, int len)
{
    for (int i = 1; i < len; i+=2) // THESE BOUNDS ARE WRONG
    {
        // PRINT STATEMENT (1): printf("index: %d\n", i); 
        // PRINT STATEMENT (2): PRINT CASES (SEEN BELOW)
        // (2) printf("my value: %d ", A[i]);
        if ((A[i] & 0x1) == 0 && (A[i] % 7 == 0)) // SWAP 1ST/3RD CONDITIONS
        {
            // (2) printf("case 1: divisible by 2\n"); 
            A[i] = -1; 
        }
        else if (A[i] % 7 == 0)
        {
            // (2) printf("case 2: divisible by 7\n"); 
            A[i] = 1;
        }
        else if ((A[i] & 0x1) == 0) // ALL THE EVEN CHECKS ARE WRONG!
        {
            // (2) printf("case 3: divisible by 2 AND 7\n"); 
            A[i] = 0;
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

    fizzed_and_buzzed(A, 10);

    int *A_res = xcalloc(sizeof(int), 8); 
    A_res[0] = 4;
    A_res[1] = 7;
    A_res[2] = 2;
    A_res[3] = 14;
    A_res[4] = 28;
    A_res[5] = 5;
    A_res[6] = 7;
    A_res[7] = 8;
    
    assert(arrs_equal(A, A_res, 10, 10));

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
 * @brief checks if two arrays are equal by looking at each element
 * @param A array of ints
 * @param B array of ints
 * @param len_A of array A
 * @param len_B of array B
 * @return whether A and B are the same array
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
