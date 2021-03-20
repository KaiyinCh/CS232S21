#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
<<<<<<< HEAD
    //TODO:copy setup func from task2
  int i;
  
  node_t * head;
  node_t *first = (node_t*)malloc(sizeof(node_t));
  node_t *second = (node_t*)malloc(sizeof(node_t));
  node_t *third = (node_t*)malloc(sizeof(node_t));

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
=======
    //TODO:copy setup func from previous task
>>>>>>> a7224f3c14bcefbb74f4b42313917f8607faa7c6
}

void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
  
  free(head->next->next);
  free(head->next);
  free(head);
}

void add(node_t ** head, char * str, int length){
    //TODO: copy add func from task2
  node_t * a = (node_t*)malloc(sizeof(node_t));
  for(int i = 0; i <= length; i++){
    a->str[i] = str[i]; 
  }
  a->next = *head;
  *head = a;
  return;
}

void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
  node_t * temp = *head;
  if(idx == 0){
    *head = temp->next;
    free(temp);
    return;
  }
  for (int i = 0; temp != NULL && i < idx-1; i++){
    temp = temp->next;
  }
  node_t * next = temp->next->next;
  free(temp->next);
  temp->next = next;
  
} 

void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
  node_t * temp = *head;
  
  while(temp != NULL){
    if (strcmp(temp->next->str, key) == 0){
      temp->next = temp->next->next;
      free(temp->next);
      return;
    }else{
      temp = temp->next;
    }
  }

  return;
  
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
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
