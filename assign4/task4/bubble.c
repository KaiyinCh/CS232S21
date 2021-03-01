/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

//public void swap(char arr, int a);

int main()
{
  char * Strings[NUM];
  int i, j;

  //printf("Please enter %d strings, one per line:\n", NUM);
  

  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length. However, each 
	 string stored in array Strings must not waste space. That is, only the buffer
	 used by fgets() to temporary store the string read from input stream needs to 
	 be LEN bytes long.  
	 Note that the newline and NULL characters will be included in LEN.
  */
 
  char temp[LEN-2];
  for (i = 0; i < NUM; i++){
    fgets(temp, LEN-2, stdin);
    char *a = (char*)malloc(sizeof(strlen(temp)+1));

    for(j = 0; j < strlen(temp); j++){
      *(a+j) = *(temp + j);
    }

    *(a+(strlen(a) - 1)) = '\0';
    Strings[i] = a;
  }
  

  // puts("\nHere are the strings in the order you entered:");

  // /* Write a for loop here to print all the strings. */

    // for (i = 0; i < NUM; i++){
    //   printf("%s\n", Strings[i]);
    // }  
  
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) Implement a swap function to swap two strings by swapping pointers
	    without copying any chars.You are not allowed to use any C library 
	    functions in swap.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */
  /* Output sorted list */


  for (i = 0; i < NUM; i++){
    for (j = 0; j < NUM-1; j++){
      if(Strings[j] < Strings[i]){
        char *temp = Strings[i];
        *Strings[i] = Strings[j];
        *Strings[j] = temp;
      }
    }
  }
  
  //puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
  for(i = 0; i < NUM; i++){
    printf("%s\n", Strings[i]);
  }


  return 0;

}