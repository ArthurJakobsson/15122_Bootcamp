#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @file ex1_correct.c
 * @brief Example (1) demonstrating print statement debugging (TA step-through)
 *
 * 15-122: Principles of Imperative Computation
 *
 * Based on printing Fibonacci sequence taken from
 * https://quescol.com/interview-preparation/fibonacci-series-in-c-program
 *
 * Adapted for use in the 15122 C Bootcamp series.
 *
 * This is a CORRECT implementation.
 *
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */


int fib(int n)
{
    int first = 0; 
    int second = 1;
    int result = 0;

    if (n <= 1) return n;

    for (int i = 1; i < n; i++)
    {
        result = first + second;
        first = second; // this line is wrong in the buggy implementation
        second = result; // this line is wrong in the buggy implementation

        // (2) PRINT STATEMENT SHOULD CORRECTLY GO HERE
    }

    // (1) FIRST INCORRECT PRINT STATEMENT GOES HERE
    return result;
}

int main()
{
    printf("Testing fib:\n");
    assert(fib(0) == 0);
    assert(fib(1) == 1); 
    assert(fib(2) == 1); 
    assert(fib(3) == 2); 
    assert(fib(4) == 3); 
    assert(fib(5) == 5);
    assert(fib(6) == 8);
    assert(fib(7) == 13);
    assert(fib(8) == 21);
    printf("All tests correct!\n");
    return 0;
} 
