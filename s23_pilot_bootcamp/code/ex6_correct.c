#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @file ex1-bad.c
 * @brief Example (6) demonstrating test cases and contracts (student)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 *
 * This is a BUGGY implementation.
 *
 * @author Arthur Jakobsson <ajakobss@andrew.cmu.edu>
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */


typedef struct list_node list_node_t;

/**
 * @brief Simple singly linked list (NULL terminated)
 *
 *
*/
typedef struct list_node {
    int data;
    list_node_t *next;
} list_node_t;




int test()
{
  printf("here");
}


int main()
{
  return test();
}
