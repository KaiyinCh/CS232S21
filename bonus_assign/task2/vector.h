//#ifndef VECTOR_H_232

#include <stdio.h>
#include <stdlib.h>
#include "frame.h"


typedef struct vector_t {
   int size;
   frame_t ** data; //point to an array
   
} vector_t;

//interface
vector_t * vector_new();
void vector_delete(vector_t *);
void vector_set(vector_t*,  int loc,  frame_t* val);
frame_t* vector_get(vector_t *, int loc);