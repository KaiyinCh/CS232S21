#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len = 0, i, count;
  char buf[MAX_BUF];

  //*check;

  // fgets(buf, MAX_BUF, getchar());
  // len = strlen(buf) - 1;
do{
fgets(buf, MAX_BUF, stdin);
len = strlen(buf);
  
  for (i = 0; i < len; i++){
    
    if (buf[i] >= 'a' && buf[i] <= 'z'){
      letter_frequency[buf[i] - 97]++;
    }
    if (buf[i] >= 'A' && buf[i] <= 'Z'){
      letter_frequency[buf[i] - 65]++;
    }
  }
 
}while (len < 1);
  
  //buf[len] = (fgets(buf, MAX_BUF, stdin));
  

//free(l);

  // while ((ch = getchar()) != EOF && len < MAX_BUF) {
  //   buf[len] = ch;
  //   ++len;
  // }
  //len = len - count;

  

  

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    // for (int i = 0; i < len; ++i)
    //   putchar(buf[i]);

    printf("%c: %d\n", 65+i, letter_frequency[i]);
    
  }
}