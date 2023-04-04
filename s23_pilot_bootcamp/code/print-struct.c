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
 * @brief Print null terminated linked list
 *
 * @param[in] first node
 */
static void printList(chonky *node) {
    printf("\t\tFriends: ");
    while (node != NULL) {
        printf(" %s - ",node->name);
        node = node->next_chonk_friend;
    }
    printf("\n");
}

/**
 * @brief Prints goose
 *
 * @param[in] goose in question
 */
void printGoose(chonky *honk) {
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
  printGoose(example);
  return 0;
}


