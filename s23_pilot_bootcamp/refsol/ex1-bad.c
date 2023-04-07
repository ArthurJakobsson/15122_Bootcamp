#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
 * ex1.c
 * Example (1) demonstrating print statement debugging (TA step-through)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * Based on printing Fibonacci sequence taken from
 * https://quescol.com/interview-preparation/fibonacci-series-in-c-program
 *
 * This is a BUGGY implementation.
 *
 * @author Liz Chu <echu2@andrew.cmu.edu>
 * @author Arthur Jakobsson <ajakobss@andrew.cmu.edu>
 */

/**
 * this function computes nth term of the fibonacci sequence
 * takes in: fibonacci term to return
 * returns: nth fibonacci term
 * TODO: fix the bugs in this function
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
        second = first;
        first = result;

    }

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
