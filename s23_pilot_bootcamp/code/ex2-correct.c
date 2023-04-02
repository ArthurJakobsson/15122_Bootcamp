#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @file ex2-correct.c
 * @brief Example (2) practicing print statement debugging (student)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *   
 * Based on solution of removing duplicates from
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/solutions/3257316/c-python-c-java-easiest-solution-o-n-time/
 * 
 * This is a CORRECT implementation.
 *
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */

// linked list node (containing integer data & next node pointer)
typedef struct list_node {
    int data;
    struct list_node* next;
} node;

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

bool no_dupes(node* L)
{
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

node* remove_duplicates(node* L)
{
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

void print_list(node* L) // ask students to write this function 
{
    node* curr = L;
    while (curr != NULL)
    {
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void free_list(node* L)
{
    while (L != NULL)
    {
        node* temp = L->next;
        free(L);
        L = temp;
    }
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
