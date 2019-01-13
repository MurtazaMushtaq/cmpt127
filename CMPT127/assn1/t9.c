#include <stdio.h>
#include <math.h>

int main(){
  int i, c, t;
  int x, y, z;
  int a = scanf("%d", &x);
  int k = scanf("%d", &y);
  int b = scanf("%d", &z);
  for(i=(z-1);i>-1;i--){
    int left = floor( i * (x/(2.0*z)) );
    int right = ceil( (x-1) + -i * (x/(2.0*z)) );  
    for(c=0;c<x;c++){
      if(c<left){
        printf(" ");
      }
      else if(c==left){
        printf("#");
      }
      else if(c==right){
        printf("#");
      }
      else if(c>left && c<right){
        if(i==(z-1) || i==0){
          printf("#");
        }
        else{
          printf(".");
        }
      }
    }
    printf("\n");
  }
  return 0;
}

