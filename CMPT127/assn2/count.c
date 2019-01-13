#include <stdio.h>

int main(){
  long unsigned int charcount=0;
  long unsigned int wordcount=0;
  long unsigned int linecount=0;
  int c;
  int check=1;

  while((c=getchar()) != EOF){
    charcount++;

    if(c == '\n'){
      linecount++;
    }

    if(check==1 && ((c>='a'&& c<='z')||(c>='A' && c<='Z')||(c=='\''))){
      wordcount++;
      check=0;
    }
    else if(!((c>='a'&& c<='z')||(c>='A' && c<='Z')||(c=='\''))){
      check=1;
    }
    else{
      continue;
    }
      
  }
  
  printf("%lu %lu %lu\n", charcount, wordcount, linecount);
  return 0;
}

