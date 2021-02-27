#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t * construct_3() {
    //Allocate three pointers: 
    //x for the first Node, and temporary pointers y and z for the other two Nodes.

    //Allocate three Node pointees and store references to them in the three pointers.

    //Dereference each pointer to store the appropriate number into the value field in its pointee.

    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 

  node_t * x = (node_t*) malloc(sizeof(node_t));

  x->value = 1;
  x->next = (node_t*) malloc(sizeof(node_t));
  x->next->value = 2;
  x->next->next = (node_t*) malloc(sizeof(node_t));
  x->next->next->value = 3;
  //x->next->next->next = (node_t*) malloc(sizeof(node_t));
  x->next->next->next = x;

  return x;

}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {

    node_t * x = construct_3();
    dump_all(x);
    free(x);

    return 0;

}

int dump_all(node_t * x) {
    printf("x -> %d\n", x->value);
    node_t * y = x->next;
    printf("%d -> %d\n", x->value, y->value);
    node_t * z = y->next;
    printf("%d -> %d\n", y->value, z->value);
    free(y);
    if(z->next != x) {
    	printf("failed");
      free(z);
	    return -1;
    } else {
        printf("%d -> %d\n", z->value, x->value);
        free(z);
        return 0;
    }
}