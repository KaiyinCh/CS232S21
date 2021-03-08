#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  int len, i;
  char buf[MAX_BUF];

  int chars = 0, words = 0, lines = 0, whitespaces = 0, uppercase = 0, lowercase = 0, digits = 0;
  

  while (fgets(buf, MAX_BUF, stdin) != NULL){
  
    len = strlen(buf);
  
    for (i = 0; i <= len; i++){
      if (buf[i] == ' '){
        whitespaces++;
      }
      if (buf[i] >= 'A' && buf[i] <= 'Z'){
        uppercase++;
      }
      if (buf[i] >= 'a' && buf[i] <= 'z'){
        lowercase++;
      }
      if (buf[i] >= '0' && buf[i] <= '9'){
        digits++;
      }
      chars++;
    }
    lines++;
  }

  chars = chars - lines;
  words = lines + whitespaces;

  printf("%d %d %d %d %d %d %d\n", chars, words, lines, whitespaces, uppercase, lowercase, digits);
}