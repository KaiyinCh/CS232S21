// #ifndef _slist_H_
// #define _slist_H_
#include "slist.h"
//#include "snode.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create(){
  struct slist * head = (struct slist *)malloc(sizeof(struct slist));

  head->front = NULL;
  head->back = NULL;
  return head;

}

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, void *data){
  // struct snode* temp = l->back;
  // temp->str = (char *)malloc((strlen(str)+1)*sizeof(char));
  // strcpy(temp->str, str);
  // temp->next = NULL;
  struct snode* temp;
  temp = snode_create(data);
  if(l->front == NULL){
    l->front = temp;
    l->back = temp;
  }else{
    l->back->next = temp;
    l->back = temp;
  }

  return temp;
}

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, void *data){
  // struct snode* temp = l->front;
  // temp->str = (char *)malloc((strlen(str)+1)*sizeof(char));
  // strcpy(temp->str, str);
  // temp->next = l->front;
  struct snode* temp;
  temp = snode_create(data);
  if(l->front == NULL){
    l->front = temp;
    l->back = temp;
  }else{
    temp->next = l->front;
    l->front = temp;
  }
  
  return temp;
}

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, void *data){
  struct snode * temp = l->front;
  while(temp != NULL){
    if (strcmp(temp->data, data) == 0){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
  
}

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){
  struct snode *temp = l->front;
  struct snode *counter;
  while (temp != NULL){
    counter = temp->next;
    snode_destroy(temp);
    temp = counter;
  }
  free(l);
  
}

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){
  printf("test");
  struct snode *temp = l->front;
  while (temp != NULL){
    printf("%s\n", (char*)temp->data);
    temp = temp->next;
  }
}

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
  int counter = 0;
  struct snode* temp = l->front;
  
  while(temp != NULL){
    counter++;
    temp = temp->next;
  }
  return (uint32_t)counter;
}
/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 */
void slist_delete(struct slist *l, void *data){
  struct snode* temp = l->front;
  struct snode* node;
  
  while(temp != NULL){
    if (strcmp(temp->data, data) == 0){
      node->next = node->next->next;
      snode_destroy(temp);
      return;
    }else{
      node = temp;
      temp = temp->next;
    }
  }
  return;
}