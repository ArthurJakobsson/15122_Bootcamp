#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "lib/xalloc.h"
#include "lib/contracts.h"

/*
 * ---------------------------------------------------------------------------
 *                                 STRUCT
 * ---------------------------------------------------------------------------
 */

typedef struct chonk chonky;

struct chonk{
  char *name;
  int height;
  int color; //categorical
  bool canadian;
  chonky *next_chonk_friend;
};

/*
 * ---------------------------------------------------------------------------
 *                             PRINTING CODE
 * ---------------------------------------------------------------------------
 */

/**
 * this function prints NULL-terminated linked list
 * takes in: node - first node of linked list
 */
static void printList(chonky *node) {
    printf("\t\tFriends: ");
    while (node != NULL) 
    {
        printf(" %s - ", node->name);
        node = node->next_chonk_friend;
    }
    printf("\n");
}

/**
 * this function prints goose
 * takes in: honk - goose in question
 */
void print_goose(chonky *honk) {
    //name and address
    printf("\tName: %s, Address %p\n", honk->name, (void *)honk);
    //integer
    printf("\t\tHeight: %d inches\n", honk->height);
    //category
    printf("\t\tColor: ");
    switch(honk->color)
    {
      case 1:
        printf("black\n");
        break;
      case 2:
        printf("orange\n");
        break;
      case 3:
        printf("white\n");
        break;
      default:
        printf("no color\n");
    }
    //boolean
    honk->canadian ? printf("\t\tFrom: Canada\n")
                   : printf("\t\tFrom: not Canada\n");
    //linked list
    printList(honk->next_chonk_friend);
}

int main()
{
    chonky *example = xcalloc(sizeof(chonky), 1);
    example->name = "Kevin";
    example->height = 13;
    example->color = 3;
    example->canadian = true;

    //friends
    chonky *f1 = xcalloc(sizeof(chonky), 1);
    f1->name = "Allen";
    chonky *f2 = xcalloc(sizeof(chonky), 1);
    f2->name = "Jeffrey";
    chonky *f3 = xcalloc(sizeof(chonky), 1);
    f3->name = "Alex";

    example->next_chonk_friend = f1;
    f1->next_chonk_friend = f2;
    f2->next_chonk_friend = f3;
    f3->next_chonk_friend = NULL;
    print_goose(example);

    free(example); 
    free(f1); 
    free(f2); 
    free(f3);
    return 0;
}


