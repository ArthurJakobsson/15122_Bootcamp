#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "lib/xalloc.h"

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
struct dna_node {
    char data;
    dna_node_t *next;
};


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
    printf("%c_", curr->data); // this doesn't seem to be the most helpful for debugging this problem...
    curr=curr->next;
  }
  printf("\n");
  return true;
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

/**
 * @brief Create a Node object with content as the data
 *
 * @param content data to be stored in node
 * @return dna_node_t* the new char
 */
dna_node_t *createNode(char content)
{
  dna_node_t *new = xcalloc(sizeof(dna_node_t),1);
  new->data = content;
  return new;
}

/**
 * @brief Get the Opposite DNA char type
 *
 * T-A and G-C
 *
 * @param content char to be flipped
 * @return char flipped char
 */
char getOppositeDNA(char content)
{
  switch(content)
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
 * @brief Create a Strand object from a string
 *
 * @param str string to be used to create a strand
 * @param flip boolean to determine to make strand or flipped strand
 * @return dna_node_t* the first node of the resultant linked list
 */
dna_node_t *createStrand(char *str, bool flip)
{
  dna_node_t *curr = NULL;
  dna_node_t *start = NULL;
  for(int i=0; str[i]!='\0';i++)
  {
    char input;
    if(!flip){
      input = str[i];
    } else {
      input = getOppositeDNA(str[i]);
    }
    if(start == NULL)
    {
      start = createNode(input);
      curr = start;
    } else {
      curr->next = createNode(input);
      curr = curr->next;
    }
  }
  return start;
}

/**
 * @brief Checks if two strands (linked lists) are equal
 *
 * (we give this to them?)
 *
 * @param first
 * @param second
 * @return true
 * @return false
 */
bool strandEqual(dna_node_t *first, dna_node_t *second)
{
  while(first!=NULL)
  {
    if(second==NULL) //first longer than second
    {
      return false;
    }
    if(first->data != second->data)
    {
      return false; //data don't match
    }
    first=first->next;
    second=second->next;
  }
  if(second!=NULL)
  {
    return false; //second longer than first
  }
  return true;
}

/**
 * @brief Tester function (we hide this?)
 *
 * @return int
 */
void test()
{
  char test1[] = "AAAA";
  char correctOutput1[] = "ATATATAT";
  dna_node_t * test_1_strand_1 = createStrand(test1, false);
  dna_node_t * test_1_strand_2 = createStrand(test1, true);
  dna_node_t * test_1_correct_output = createStrand(correctOutput1, false);
  dna_node_t * twistedDNA1 = twist_my_dna(test_1_strand_1, test_1_strand_2);
  assert(strandEqual(test_1_correct_output, twistedDNA1));
  dna_free(test_1_correct_output);
  dna_free(twistedDNA1); //twisted should contain all the strand 1 and 2 nodes

  char test2[] = "GGGG";
  char correctOutput2[] = "GCGCGCGC";
  dna_node_t * test_2_strand_1 = createStrand(test2, false);
  dna_node_t * test_2_strand_2 = createStrand(test2, true);
  dna_node_t * test_2_correct_output = createStrand(correctOutput2, false);
  dna_node_t * twistedDNA2 = twist_my_dna(test_2_strand_1, test_2_strand_2);
  assert(strandEqual(test_2_correct_output, twistedDNA2));
  dna_free(test_2_correct_output);
  dna_free(twistedDNA2);
}

/**
 * @brief Main function to call tester (we hide this too?)
 *
 * @return int
 */
int main()
{
  test();
  return 0;
}
