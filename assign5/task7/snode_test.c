#include <stdio.h>
#include <string.h>
#include "snode.h"
//#include "snode.c"
//typedef struct snode node_t;

// global variables (data segment)

struct snode *n1, *n2, *n3, *p;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create snodes
  // TODO: modify func calls to snode_create
  // to match with new prototypes.
  //snode_t *p;
  n1 = snode_create("hello");
  n2 = snode_create("there");
  n3 = snode_create("prof");

  printf("snode_test running...\n");

  // manually "link" the nodes together.
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  // p points to node n1 initially
  p = n1;

  while (p != NULL) {
    // Complete this line to print the current node's string and   
    // length (you can use strlen!)
    
    int len = strlen(p->str);
    printf("str: %s - length: %d\n", p->str, len); // TODO
    p = p->next;

    // TODO: add code to move p to point to next node
    // until you add this line, this program will have an infinite loop.
  }

  return 0;
}
