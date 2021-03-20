#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from task1
  int i;
  
  node_t * head;
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

  //head->next = first;
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
  free(head->next->next->next->next);
  free(head->next->next->next);
  free(head->next->next);
  free(head->next);
  free(head);
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
  node_t * a = (node_t*)malloc(sizeof(node_t));
  for(int i = 0; i <= length; i++){
    a->str[i] = str[i]; 
  }
  a->next = *head;
  *head = a;
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
  node_t * head = setup();
  add(&head, "hi", 2);
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
