#include <stdio.h>

int main(int argc, char *argv[]) {

  char str[10090];
  int ch, n = 0, i;

  while ((ch = getchar()) != EOF && n < 1000) {
    str[n] = ch;
    ++n;
  }

  for (i = 0; i < n; i++){
   if (str[i] >= 'a' && str[i] <= 'z'){
    str[i] = str[i] - 32;
   }
  }

  for (int i = 0; i < n; ++i)
    putchar(str[i]);

  return 0;
}

