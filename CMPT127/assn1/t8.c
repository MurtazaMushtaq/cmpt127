#include <stdio.h>

int main()
{
  int i, c, t;
  int x, y, z;
  int a = scanf("%d", &x);
  int b = scanf("%d", &y);
  for(c=0; c<x; c++){
     printf("#");
  }
  if(y==1){
  }
  else{
    printf("\n");
    for(i=0; i<y-2; i++){
      printf("#");
      for(c=0; c<x-2; c++){
       printf(".");
      }
    printf("#");
      printf("\n");
    }
    for(t=0; t<x; t++){
       printf("#");
    }
  }
  printf("\n"); 
  return 0;
}

