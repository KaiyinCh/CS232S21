/******************************************************
* File: asciimation.c
*
* This is implementation of asciimation
*
******************************************************/
#include "asciimation.h"
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_num_frames(char *path) {
	DIR * dir;
	struct dirent * pdir;
	dir = opendir(path);
	int n = 0;

	if(dir == NULL){
    printf("Cannot open directory '%s'\n", path);
    return 1;
  }
  else{
    while((pdir = readdir(dir))) {
      if(strcmp(pdir->d_name, ".") != 0 && strcmp(pdir->d_name, "..") != 0) {
        n++;
      }
		}
    closedir(dir);
  }
	return n;

}

asciimation_t * asciimation_new(char * path, int fps){
	asciimation_t * ascm = (asciimation_t *) malloc(sizeof(asciimation_t));
	if(!ascm) {
		perror("failed allocation\n");
		return 0;
	}
	//figure out how many frames are in the dir?
	int n = get_num_frames(path);
	//create a vector of frames
	ascm->frames = vector_new();
	// we know the number of frames, we can simply reconstruct the name of each ascii file, and construct a frame obj for 
	// each ascii file. Must implement frame_new first
	for(int i=0; i<n; i++) {
		char asciipath[4096];
		strcpy(asciipath, path);
		int len = strlen(asciipath);
		if(asciipath[len-1] != '/') 
			sprintf(asciipath+len, "/%d", i+1);
		else	
			sprintf(asciipath+len, "%d", i+1);
		
		struct frame_t * frame = frame_new(asciipath,i);
		vector_set(ascm, i, frame);
	}
	return ascm;
}

void asciimation_delete(asciimation_t * ascm){
	//reversed steps of asciimation_new
  vector_delete(ascm->frames);
	free(ascm);
}

void asciimation_play(asciimation_t * ascm){
  for(int i=0; i < ascm->frames->size; ++i) {
		printf("%s",vector_get_frame_content(ascm->frames, i));
	  sleep(ascm->frames_per_second * (vector_get_frame_rep_counter(ascm->frames, i)/15));
    system("clear");
  }
}

void asciimation_reverse(asciimation_t * ascm){
	//same logic as above, only difference is loop through the vector backward.
  for(int i = ascm->frames->size; i > 0; --i) {
		printf("%s",vector_get_frame_content(ascm->frames, i-1));
		sleep(ascm->frames_per_second * (vector_get_frame_rep_counter(ascm->frames, i-1)/15));
    system("clear");
	}
}


