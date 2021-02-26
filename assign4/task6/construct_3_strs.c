#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} node_t;

node_t * construct_3_strs() {

  node_t * x = (node_t*) malloc(sizeof(node_t));
  x->
  //x->value = "CS232";
  //strcpy(x->value, "CS232");
  x->next = (node_t*) malloc(sizeof(node_t));
  //strcpy(x->next, "is");
  x->next->value = "is";
  x->next->next = (node_t*) malloc(sizeof(node_t));
  x->next->next->value = "awesome";
  //strcpy(x->next->next, "awesome");
  //x->next->next->next = (node_t*) malloc(sizeof(node_t));
  x->next->next->next = x;

  return x;
    //return NULL;//just to pass compiler, please edit as needed.
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
  node_t *x = (node_t*)malloc(sizeof(node_t));
    x = construct_3_strs();
    dump_all(x);
    free(x);
}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    free(y);
    if(z->next != x) {
    	printf("failed");
      free(z);
	  return -1;
    } else {
      free(z);
      return 0;
    }
}