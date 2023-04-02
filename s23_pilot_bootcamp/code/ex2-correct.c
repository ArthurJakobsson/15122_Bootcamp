#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib/contracts.h"

/**
 * @file ex2-correct.c
 * @brief Example (2) practicing print statement debugging (student)
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

/** @brief struct of linked list node (containing int data & next pointer) */
typedef struct list_node {
    int data;
    struct list_node* next;
} node;

/*
 * ---------------------------------------------------------------------------
 *                           SHORT HELPER FUNCTIONS
 * ---------------------------------------------------------------------------
 */

/** 
 * @brief checks if list starting at node L is sorted 
 * THIS IS A CORRECT FUNCTION! 
 */
bool is_sorted(node* L)
{
    node* curr = L;
    node* next = L->next;
    while (next != NULL)
    {
        if (curr->data > next->data) return false;
        curr = next;
        next = next->next;
    }
    return true;
}

/** 
 * @brief checks if list starting at node L has duplicates
 * @pre list L has to be sorted
 * THIS IS A CORRECT FUNCTION! 
 */
bool no_dupes(node* L)
{
    REQUIRES(is_sorted(L));

    node* curr = L;
    node* next = L->next;
    while (next != NULL)
    {
        if (curr->data == next->data) return false;
        curr = next;
        next = next->next;
    }
    return true;
}

/** 
 * @brief helper function to free list
 * THIS IS A CORRECT FUNCTION! 
 */
void free_list(node* L)
{
    while (L != NULL)
    {
        node* temp = L->next;
        free(L);
        L = temp;
    }
}

/** 
 * @brief prints out the lsit starting at L for debugging purposes
 * TODO: IMPLEMENT ME TO HELP DEBUG
 */
void print_list(node* L) 
{
    node* curr = L;
    while (curr != NULL)
    {
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

/* ---------------------- END SHORT HELPER FUNCTIONS ----------------------- */

/**
 * @brief removes duplicates from a sorted list starting at L
 * @pre list L must be sorted
 * TODO: fix the bug in this function
 */
node* remove_duplicates(node* L)
{
    REQUIRES(is_sorted(L)); 
    node* curr = L;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == curr->data)
        {
            curr->next = curr->next->next; // lines 60 and 64 are swapped
        }
        else
        {
            curr = curr->next; // lines 60 and 64 are swapped
        }
    }
    return L;
}

int main()
{
    node* L1 = malloc(sizeof(node));
    L1->data = 3; 
    L1->next = malloc(sizeof(node));
    L1->next->data = 3;
    L1->next->next = malloc(sizeof(node));
    L1->next->next->data = 5; 
    L1->next->next->next = malloc(sizeof(node));
    L1->next->next->next->data = 7; 
    L1->next->next->next->next = malloc(sizeof(node));
    L1->next->next->next->next->data = 7; 

    node* L2 = malloc(sizeof(node));
    L2->data = 1; 
    L2->next = malloc(sizeof(node));
    L2->next->data = 1;
    L2->next->next = malloc(sizeof(node));
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
    while (L1 != NULL)
    return 0;
} 
