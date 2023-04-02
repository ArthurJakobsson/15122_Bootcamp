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


typedef struct dna_node dna_node_t;

/**
 * @brief Simple singly linked list (NULL terminated)
*/
typedef struct dna_node {
    char data;
    dna_node_t *next;
} dna_node_t;


/**
 * @brief
 *
 * NO ALLOCATING IN HERE!
 *
 * @param first_strand
 * @param second_strand
 * @return dna_node_t*
 */
dna_node_t *twist_my_dna(dna_node_t *first_strand, dna_node_t *second_strand)
{
  dna_node_t *start = first_strand;
  dna_node_t *first_curr = first_strand;
  dna_node_t *second_curr = second_strand;
  while(first_curr!=NULL)
  {
    dna_node_t *temp_first_next = first_curr->next;
    first_curr->next = second_curr;
    first_curr = second_curr;
    second_curr = temp_first_next;
  }
  return start;
}

/**
 * @brief Function to check integrity of linked list
 *
 * TODO: Write contracts!
 *
 * @param start
 * @return bool
 */
bool check_list(dna_node_t *start)
{
  dna_node_t *curr = start;
  while(curr!=NULL)
  {
    printf("_%c_", curr->data); // this doesn't seem to be the most helpful for debugging this problem...
    curr=curr->next;
  }
}

void dna_free(dna_node_t *start)
{
  dna_node_t *curr = start;
  while(curr!=NULL)
  {
    dna_node_t *next = curr->next;
    free(curr);
    curr = next;
  }
}


int test()
{
  for(int i=0; i<7; i++)
  {

  }
}

// T-A
// G-C

int main()
{
  return test();
}
