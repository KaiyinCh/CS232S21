#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} node_t;

node_t * construct_3_strs() {
  node_t *x, *y, *z;

  x = (node_t*) malloc(sizeof(node_t)*3);
  x->value = (char *) malloc(sizeof(char) *5);
  x->value = "CS232";

  y = (node_t*) malloc(sizeof(node_t)*3);
  y->value = (char *) malloc(sizeof(char) *5);
  y->value = "is"; 

  z = (node_t*) malloc(sizeof(node_t)*3);
  z->value = (char *) malloc(sizeof(char) *5);
  z->value = "awesome";

  x->next = y;
  y->next = z;
  z->next = x;

  return x;
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
  node_t *x = (node_t*)malloc(sizeof(node_t));
    x = construct_3_strs();
    dump_all(x);
    //free(x->value);
    free(x);
    return 0;
}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    //free(y->value);
    free(y);
    if(z->next != x) {
    	printf("failed");
      //free(z->value);
      free(z);
	  return -1;
    } else {
     // free(z->value);
      free(z);
      return 0;
    }
}