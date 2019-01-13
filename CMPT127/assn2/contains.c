#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
  char* i;
  i = strstr(argv[1], argv[2]);
  if(i){
    printf("true\n");
  }
  else{
    printf("false\n");
  }
}
