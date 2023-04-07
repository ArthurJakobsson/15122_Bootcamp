#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "xalloc.h"
#include "contracts.h"

typedef struct dna_node {
    char data;
    struct dna_node* next;
} dna_node_t;

/*
 * ---------------------------------------------------------------------------
 *                 DON'T WORRY ABOUT ANYTHING BELOW HERE
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
