char password[8] = "secret";
int main() {
  char input[8];
  int i;
   
  printf("please enter your password\n");
  scanf("%s", input);
    
  for(i = 0; i < 8; i++){
    if(65 <= input[i] && 90 >= input[i]){
      input[i] = 32 + input[i];
    }
  }

  if(strcmp(input, password)==0){
    return 0;
  }else{
    return -1;
  }

}
