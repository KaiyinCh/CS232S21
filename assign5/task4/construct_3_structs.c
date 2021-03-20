#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
 
  int i;
  
  node_t * head;// = (node_t*)malloc(sizeof(node_t));
  node_t * first = (node_t*)malloc(sizeof(node_t));
  node_t * second = (node_t*)malloc(sizeof(node_t));
  node_t * third = (node_t*)malloc(sizeof(node_t));

  for(i = 0; i <= 5; i++){
    first->str[i] = "hello\0"[i]; 
  }
  for(i = 0; i <= 5; i++){
    second->str[i] = "there\0"[i]; 
  }
  for(i = 0; i <= 4; i++){
    third->str[i] = "prof\0"[i]; 
  }

  first->next = second;
  second->next = third;
  third->next = NULL;
  head = first;
     
  return head;
}

void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals  
  free(head->next->next->next);
  free(head->next->next);
  free(head->next);
  free(head);
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
      printf("%s ", cur->str);
	    cur = cur->next;
    }
    printf("\ndone\n ");
}
