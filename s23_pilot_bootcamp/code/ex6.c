#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "lib/xalloc.h"
#include "lib/contracts.h"

/**
 * @file ex6.c
 * @brief Example (6) demonstrating test cases and contracts (student)
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
 * @brief struct of linked list node (containing int data & next pointer)
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
 * @brief frees strand from start
 * THIS IS A CORRECT FUNCTION
 */
void dna_free(dna_node_t *start);

/**
 * @brief checks if two strands (linked lists) are equal
 * THIS IS A CORRECT FUNCTION
 */
bool strand_equal(dna_node_t *first, dna_node_t *second);

/**
 * @brief create a node object with content as the data
 * THIS IS A CORRECT FUNCTION
 */
dna_node_t *create_node(char content);

/**
 * @brief create a strand object from a string
 * THIS IS A CORRECT FUNCTION
 */
dna_node_t *create_strand(char *str, bool flip);

/**
 * @brief get the opposite DNA char type (T-A and G-C)
 * THIS IS A CORRRECT FUNCTION
 */
char get_opposite_dna(char content);


/*
 * ---------------------------------------------------------------------------
 *                 HELPER FUNCTIONS (A place to add contracts?)
 * ---------------------------------------------------------------------------
 */

/**
 * @brief checks integrity of linked list (currently prints)
 * @param start of DNA list
 * @return whether list is valid
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
 * @brief creates twisted DNA strand based on two individual DNA strands *
 * @param first_strand to twist
 * @param second_strand to twist
 * @return twisted DNA strand that combines first and second
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
 * @brief tester function
 */
void test()
{
    char test1[] = "AA";
    dna_node_t * test_1_strand_1 = create_strand(test1, false);
    dna_node_t * test_1_strand_2 = create_strand(test1, true);
    dna_node_t * twisted_dna_1 = twist_my_dna(test_1_strand_1, test_1_strand_2);
    dna_free(twisted_dna_1);
    //twisted should contain all the strand 1 and 2 nodes
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
 * @brief frees strand from start
 * @param start of dna strand
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
 * @brief checks if two strands (linked lists) are equal
 * @param first strand to check
 * @param second strand to check
 * @return whether two strands are the same
 * THIS IS A CORRECT FUNCTION
 */
bool strand_equal(dna_node_t *first, dna_node_t *second)
{
    while (first != NULL)
    {
        if (second == NULL) //first longer than second
        {
            return false;
        }
        if (first->data != second->data)
        {
            return false; //data don't match
        }
        first = first->next;
        second = second->next;
    }

    if (second != NULL)
    {
        return false; //second longer than first
    }
    return true;
}

/**
 * @brief create a node object with content as the data
 * @param content data to be stored in node
 * @return resulting node
 * THIS IS A CORRECT FUNCTION
 */
dna_node_t *create_node(char content)
{
    dna_node_t *new = xcalloc(sizeof(dna_node_t), 1);
    new->data = content;
    return new;
}

/**
 * @brief get the opposite DNA char type (T-A and G-C)
 * @param content char to be flipped
 * @return flipped char
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
 * @brief create a strand object from a string
 * @param str string to be used to create a strand
 * @param flip boolean to determine to make strand or flipped strand
 * @return the first node of the resultant linked list
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
