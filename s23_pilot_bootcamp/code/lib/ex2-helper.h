#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "contracts.h"
#include "xalloc.h"

/**
 * this function checks if two arrays are equal by looking at each element
 * takes in: A - array of ints; B - array of ints; 
 *           len_A of array A; len_B of array B
 * returns: whether A and B are the same array
 * THIS IS A CORRECT FUNCTION!
 */
bool arrs_equal(int *A, int *B, int len_A, int len_B);
