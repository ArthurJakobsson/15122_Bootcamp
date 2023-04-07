#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "lib/xalloc.h"
#include "lib/contracts.h"
#include "lib/ex6-helper.h"

/**
 * ex6.c
 * Example (6) demonstrating test cases and contracts (student)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
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
 * struct of linked list node (containing int data & next pointer)
 * note: null-terminated lists
 * note: defined in header file
 */
// typedef struct dna_node {
//     char data;
//     struct dna_node* next;
// } dna_node_t;

/*
 * ---------------------------------------------------------------------------
 *                          SHORT HELPER FUNCTIONS
 * ---------------------------------------------------------------------------
 */

/**
 * this function frees strand from start
 * takes in: start -  of dna strand
 * THIS IS A CORRECT FUNCTION
 */
void dna_free(dna_node_t *start);

/**
 * this function checks if two strands (linked lists) are equal
 * takes in: first - strand to check; second - strand to check
 * returns: whether two strands are the same
 * THIS IS A CORRECT FUNCTION
 */
bool strand_equal(dna_node_t *first, dna_node_t *second);

/**
 * this function create a node object with content as the data
 * takes in: content - data to be stored in node
 * returns: resulting node
 * THIS IS A CORRECT FUNCTION
 */
dna_node_t *create_node(char content);

/**
 * this function get the opposite DNA char type (T-A and G-C)
 * takes in: content - char to be flipped
 * returns: flipped char
 * THIS IS A CORRRECT FUNCTION
 */
char get_opposite_dna(char content);

/**
 * this function create a strand object from a string
 * takes in: str - string to be used to create a strand; 
 *           flip - boolean to determine to make strand or flipped strand
 * returns: the first node of the resultant linked list
 * THIS IS A CORRECT FUNCTION
 */
dna_node_t *create_strand(char *str, bool flip);

/*
 * ---------------------------------------------------------------------------
 *                 HELPER FUNCTIONS (A place to add contracts?)
 * ---------------------------------------------------------------------------
 */

/**
 * this function checks integrity of linked list (currently prints)
 * takes in: start - of DNA list
 * returns: whether list is valid
 * TODO: write contracts for this function
 */
bool check_list(dna_node_t *start)
{
    dna_node_t *curr = start;
    while (curr != NULL)
    {
        printf("data : %c\n", curr->data);
        printf("pointer: %p \n", (void*)curr);
        curr = curr->next;
    }
    printf("\n");
    return true;
}

/*
 * ---------------------------------------------------------------------------
 *                                   BUGS!
 * ---------------------------------------------------------------------------
 */

/**
 * this function creates twisted DNA strand based on two individual DNA strands *
 * takes in: first_strand - to twist; second_strand - to twist
 * returns: twisted DNA strand that combines first and second
 * TODO: fix the bugs in this function
 */
dna_node_t *twist_my_dna(dna_node_t *first_strand, dna_node_t *second_strand)
{
    dna_node_t *start = second_strand;
    dna_node_t *first_curr = first_strand;
    dna_node_t *second_curr = second_strand;

    while (first_curr->next != NULL) // where could I add contracts in here?
    {
        printf("current data: %c \n", first_curr->data);
        dna_node_t *temp_first_next = first_curr->next;
        first_curr->next = second_curr;

        second_curr = temp_first_next;
        // what should the next block in the chain be? what contract can I write
    }

    ASSERT(check_list(start));
    return start;
}

/*
 * ---------------------------------------------------------------------------
 *                                Test cases
 * ---------------------------------------------------------------------------
 */

/**
 * this is a tester function
 */
void test()
{
    char test1[] = "AA";
    dna_node_t * test_1_strand_1 = create_strand(test1, false);
    dna_node_t * test_1_strand_2 = create_strand(test1, true);
    dna_node_t * twisted_dna_1 = twist_my_dna(test_1_strand_1, test_1_strand_2);
    dna_free(twisted_dna_1);
    // twisted should contain all the strand 1 and 2 nodes
}

int main()
{
    test();
    return 0;
}
