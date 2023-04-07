#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "lib/xalloc.h"
#include "lib/contracts.h"

/**
 * ex6-correct.c
 * Example (6) demonstrating test cases and contracts (student)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * This is a CORRECT implementation.
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
 * */
typedef struct dna_node {
    char data;
    struct dna_node* next;
} dna_node_t;

/*
 * ---------------------------------------------------------------------------
 *                 SHORT HELPER FUNCTIONS (Defined in full below)
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
        // should have an even number of data
        if(curr->next == NULL)
        {
            return false;
        }

        dna_node_t *first = curr;
        dna_node_t *second = curr->next;

        printf("1st data : %c\n", first->data);
        printf("1st pointer: %p \n", (void*)first);

        printf("1st data : %c\n", second->data);
        printf("1st pointer: %p \n", (void*)second);

        if(get_opposite_dna(first->data) != second->data)
        {
            return false;
        }
        curr = curr->next->next;
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
    dna_node_t *start = first_strand; // change this from second to first
    dna_node_t *first_curr = first_strand;
    dna_node_t *second_curr = second_strand;

    while (first_curr != NULL) // remove next
    {
        printf("first data: %c \n", first_curr->data);
        printf("second data: %c \n", second_curr->data);
        ASSERT(get_opposite_dna(first_curr->data) == second_curr->data);

        dna_node_t *temp_first_next = first_curr->next;
        dna_node_t *temp_second_next = second_curr->next;
        first_curr->next = second_curr;
        second_curr->next = temp_first_next;

        first_curr = temp_first_next;
        second_curr = temp_second_next;
    }

    ASSERT(first_curr == NULL && second_curr == NULL);
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

    char test2[] = "AAAA";
    char correctOutput2[] = "ATATATAT";
    dna_node_t * test_2_strand_1 = create_strand(test2, false);
    dna_node_t * test_2_strand_2 = create_strand(test2, true);
    dna_node_t * test_2_correct_output = create_strand(correctOutput2, false);
    dna_node_t * twistedDNA2 = twist_my_dna(test_2_strand_1, test_2_strand_2);
    ASSERT(strand_equal(test_2_correct_output, twistedDNA2));
    dna_free(test_2_correct_output);
    dna_free(twistedDNA2); 
    // twisted should contain all the strand 1 and 2 nodes

    char test3[] = "TCGA";
    char correctOutput3[] = "TACGGCAT";
    dna_node_t * test_3_strand_1 = create_strand(test3, false);
    dna_node_t * test_3_strand_2 = create_strand(test3, true);
    dna_node_t * test_3_correct_output = create_strand(correctOutput3, false);
    dna_node_t * twistedDNA3 = twist_my_dna(test_3_strand_1, test_3_strand_2);
    ASSERT(strand_equal(test_3_correct_output, twistedDNA3));
    dna_free(test_3_correct_output);
    dna_free(twistedDNA3);

    char test4[] = "";
    char correctOutput4[] = "";
    dna_node_t * test_4_strand_1 = create_strand(test4, false);
    dna_node_t * test_4_strand_2 = create_strand(test4, true);
    dna_node_t * test_4_correct_output = create_strand(correctOutput4, false);
    dna_node_t * twistedDNA4 = twist_my_dna(test_4_strand_1, test_4_strand_2);
    ASSERT(strand_equal(test_4_correct_output, twistedDNA4));
    dna_free(test_4_correct_output);
    dna_free(twistedDNA4);
}

int main()
{
    test();
    return 0;
}

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
void dna_free(dna_node_t *start)
{
    dna_node_t *curr = start;
    while (curr!=NULL)
    {
        dna_node_t *next = curr->next;
        free(curr);
        curr = next;
    }
}

/**
 * this function checks if two strands (linked lists) are equal
 * takes in: first - strand to check; second - strand to check
 * returns: whether two strands are the same
 * THIS IS A CORRECT FUNCTION
 */
bool strand_equal(dna_node_t *first, dna_node_t *second)
{
    while (first != NULL)
    {
        if (second == NULL) // first longer than second
        {
            return false;
        }
        if (first->data != second->data)
        {
            return false; // data don't match
        }
        first = first->next;
        second = second->next;
    }

    if (second != NULL)
    {
        return false; // second longer than first
    }
    return true;
}

/**
 * this function create a node object with content as the data
 * takes in: content - data to be stored in node
 * returns: resulting node
 * THIS IS A CORRECT FUNCTION
 */
dna_node_t *create_node(char content)
{
    dna_node_t *new = xcalloc(sizeof(dna_node_t), 1);
    new->data = content;
    return new;
}

/**
 * this function get the opposite DNA char type (T-A and G-C)
 * takes in: content - char to be flipped
 * returns: flipped char
 * THIS IS A CORRRECT FUNCTION
 */
char get_opposite_dna(char content)
{
    switch (content)
    {
        case 'A':
            return 'T';
            break;
        case 'T':
            return 'A';
            break;
        case 'G':
            return 'C';
            break;
        case 'C':
            return 'G';
            break;
        default:
            printf("Impossible DNA element passed");
    }
    printf("Failed to invert");
    return 'X';
}

/**
 * this function create a strand object from a string
 * takes in: str - string to be used to create a strand; 
 *           flip - boolean to determine to make strand or flipped strand
 * returns: the first node of the resultant linked list
 * THIS IS A CORRECT FUNCTION
 */
dna_node_t *create_strand(char *str, bool flip)
{
    dna_node_t *curr = NULL;
    dna_node_t *start = NULL;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char input;
        if (!flip)
        {
            input = str[i];
        }
        else
        {
            input = get_opposite_dna(str[i]);
        }

        if(start == NULL)
        {
            start = create_node(input);
            curr = start;
        }
        else
        {
            curr->next = create_node(input);
            curr = curr->next;
        }
    }
    return start;
}
