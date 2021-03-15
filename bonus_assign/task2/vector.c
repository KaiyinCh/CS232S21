#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

vector_t * vector_new(int n){
	vector_t * ret = (vector_t*) malloc(sizeof(vector_t));

	if(ret == NULL) {
		perror("failed alloc");
		return NULL;
	}

	ret->size = n;
	ret->data = (frame_t **) malloc(sizeof(frame_t)*n);
	if(ret->data == NULL) {
		perror("failed alloc");
		return NULL;
	}

	return ret;
}

void vector_delete(vector_t * v){
  for(int i = v->size-1; i >= 0; i--){
    frame_delete(v->data[i]);
  }
  free(v->data);
  free(v);
}

void vector_set(vector_t* v,  int loc, frame_t* val){

  v->data[loc]= val;
  v->data[loc]->id = val->id;
  v->data[loc]->rep_counter = val->rep_counter;

}

char* vector_get_frame_content(vector_t * v, int i){
	return frame_get_content (v->data[i]);
}

int vector_get_frame_rep_counter(vector_t * v, int i){
	return frame_get_rep_counter(v->data[i]);
}
