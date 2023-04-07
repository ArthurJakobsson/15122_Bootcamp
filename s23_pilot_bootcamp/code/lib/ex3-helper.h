#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "xalloc.h"
#include "contracts.h"

typedef struct list_node {
    int data;
    struct list_node *next;
} node;

/**
 * this function checks if list starting at node L is sorted
 * takes in: L - start node of list
 * THIS IS A CORRECT FUNCTION
 */
bool is_sorted(node *L);

/**
 * this function checks if list starting at node L has duplicates
 * takes in: L - start node of list
 * precondition: list L has to be sorted
 * THIS IS A CORRECT FUNCTION
 */
bool no_dupes(node *L);

/**
 * this is a helper function to free list
 * takes in: L - start node of list
 * THIS IS A CORRECT FUNCTION
 */
void free_list(node *L);

/**
 * this function prints out the list starting at L for debugging purposes
 * takes in: L - start node of list
 * THIS IS A CORRECT FUNCTION
 */
void print_list(node *L);
