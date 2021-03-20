/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "mystring.h"

/* Define what our struct is */
struct mystring_t {
	size_t size;
	char *data;
  mystring_t *next;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new mystring */
mystring_t *bad_string_new() {
	/* Create the string and a pointer to it */
        /*This is a bad constructor as v gets destroyed once contructor returns*/
	mystring_t *retval, v;
	retval = &v;

	/* Initialize attributes */
	retval->size = 1; //why size+1? size is the actual char lenght. 
			  //we must reseve an extra space for null
	retval->data = (char*) malloc((retval->size+1)*sizeof(char));
	if (retval->data == NULL) {
		allocation_failed();
	}

	retval->data[0] = ' ';
	retval->data[retval->size] = '\0';
	return retval;
}

/* Another suboptimal way of creating a string */
mystring_t also_bad_string_new() {
	/* Create the string */
	/*why is this bad? does v get destroyed upon returning? */
	mystring_t s;

	/* Initialize attributes */
	s.size = 1; //why size+1? an extra space for null
	s.data = (char*) malloc((s.size+1)*sizeof(char));
	if (s.data == NULL) {
		allocation_failed();
	}
	s.data[0] = ' ';
	s.data[s.size] = '\0';
	return s;
}

/* Create a new string with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
mystring_t *mystring_new() {
	//YOUR CODE HERE
  mystring_t * retval = (mystring_t *) malloc(sizeof(mystring_t));
  if (retval == NULL){
    perror("failed allocation");
    return NULL;
  }
  retval->size = 1;
  retval->data = (char *) malloc(sizeof(char) * 1);
  if(retval->data == NULL){
    perror("failed to allocation data, OOM");
    return NULL;
  }

  retval->data[0] = ' ';
  
	return retval;
}

/* Return the value at the specified location/component "loc" of the mystring */
char mystring_get(mystring_t *s, size_t loc) {
	//YOUR CODE HERE
  if (loc < s->size && loc >= 0){
    return s->data[loc];
  }
  else{
    //perror("Out of bound.");
    return '\0';
  }
  
}

/* Free up the memory allocated for the passed mystring.
   Remember, you need to free up ALL the memory that was allocated. */
void mystring_delete(mystring_t *s) {
	/* YOUR CODE HERE */
  mystring_t* temp = s;
  while(temp->next != NULL){
    temp = temp->next;
    mystring_delete(temp);
    return;
  }
  free(temp->data);
  free(temp);
}

int mystring_get_len(mystring_t *s) {
	/* YOUR CODE HERE */
  return s->size;
}

char* mystring_get_data(mystring_t *s) {  
  /* YOUR CODE HERE */
  mystring_t *temp = s;
  while(temp->next != NULL){
    temp = temp->next;
    mystring_get_data(temp);
    printf("%s", temp->data);
  }
	return s->data;
}

void mystring_cat(mystring_t *s, char *s2) {
	/* YOUR CODE HERE*/
  size_t len;
  int j=0;
  for (len = 0; *(s2+len) != '\0'; len++){
    len++;
  }
  s->data = (char *)realloc(s->data, sizeof(char)*(s->size + len));
  for(int i = s->size; i < (s->size+len); i++){
    s->data[i] = *(s2+j);
    j++;
  }
  s->size = s->size + len;
  
}

/* Set a value in the mystring. If the extra memory allocation fails, call
   allocation_failed(). Unset space should be value of space */
void mystring_set(mystring_t *s, size_t loc, char value) {
	/* YOUR CODE HERE*/
  int i;

  if(loc < s->size && loc >= 0){
    s->data[loc] = value;
  }
  else{
    s->data = (char *)realloc(s->data, sizeof(char) * loc+1);
    for(i = s->size; i < loc+1; i++){
      s->data[i] = 0;
    }

    s->data[loc] = value;
    s->size = loc + 1;
  }

  return;
}
