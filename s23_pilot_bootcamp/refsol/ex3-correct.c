#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib/xalloc.h"
#include "lib/contracts.h"

/**
 * ex3-correct.c
 * Example (3) practicing valgrind debugging (TA step-through)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * Based on solution of removing duplicates from
 * https://tinyurl.com/remove-dupes
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
typedef struct list_node {
    int data;
    struct list_node *next;
} node;

/*
 * ---------------------------------------------------------------------------
 *                 SHORT HELPER FUNCTIONS (Defined in full below)
 * ---------------------------------------------------------------------------
 */

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

/*
 * ---------------------------------------------------------------------------
 *                                   BUGS!
 * ---------------------------------------------------------------------------
 */

/**
 * this function removes duplicates from a sorted list starting at L
 * precondition: list L must be sorted
 * TODO: fix the bugs in this function
 */
node* remove_duplicates(node *L)
{
    REQUIRES(is_sorted(L));
    node *curr = L;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == curr->data)
        {
            node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else
        {
            curr = curr->next;
            // free(curr); <- remove this line
        }
    }
    return L;
}

// TODO: fix the bugs in this function
int main()
{
    node *L1 = calloc(sizeof(node), 1);
    L1->data = 3;
    L1->next = calloc(sizeof(node), 1);
    L1->next->data = 3;
    L1->next->next = calloc(sizeof(node), 1);
    L1->next->next->data = 5;
    L1->next->next->next = calloc(sizeof(node), 1);
    L1->next->next->next->data = 7;
    L1->next->next->next->next = calloc(sizeof(node), 1);
    L1->next->next->next->next->data = 7;

    node *L2 = calloc(sizeof(node), 1);
    L2->data = 1;
    L2->next = calloc(sizeof(node), 1);
    L2->next->data = 1;
    L2->next->next = calloc(sizeof(node), 1);
    L2->next->next->data = 1;

    L1 = remove_duplicates(L1);
    L2 = remove_duplicates(L2);
    print_list(L1);
    print_list(L2);
    assert(is_sorted(L1) && no_dupes(L1));
    assert(is_sorted(L2) && no_dupes(L2));

    printf("All tests passed!\n");
    free_list(L1);
    free_list(L2);
    // L2->next = NULL; <- remove this line

    return 0;
}

/*
 * ---------------------------------------------------------------------------
 *                 DON'T WORRY ABOUT ANYTHING BELOW HERE
 * ---------------------------------------------------------------------------
 */

/**
 * this function checks if list starting at node L is sorted
 * takes in: L - start node of list
 * THIS IS A CORRECT FUNCTION
 */
bool is_sorted(node *L)
{
    node *curr = L;
    node *next = L->next;
    while (next != NULL)
    {
        if (curr->data > next->data) return false;
        curr = next;
        next = next->next;
    }
    return true;
}

/**
 * this function checks if list starting at node L has duplicates
 * takes in: L - start node of list
 * precondition: list L has to be sorted
 * THIS IS A CORRECT FUNCTION
 */
bool no_dupes(node *L)
{
    REQUIRES(is_sorted(L));

    node *curr = L;
    node *next = L->next;
    while (next != NULL)
    {
        if (curr->data == next->data) return false;
        curr = next;
        next = next->next;
    }
    return true;
}

/**
 * this is a helper function to free list
 * takes in: L - start node of list
 * THIS IS A CORRECT FUNCTION
 */
void free_list(node *L)
{
    node *temp;
    while (L != NULL)
    {
        temp = L->next;
        free(L);
        L = temp;
    }

}

/**
 * this function prints out the list starting at L for debugging purposes
 * takes in: L - start node of list
 * THIS IS A CORRECT FUNCTION
 */
void print_list(node *L)
{
    node *curr = L;
    while (curr != NULL)
    {
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
