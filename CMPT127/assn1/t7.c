#include <stdio.h>

int main()
{
  int i = 0;
  int cou = 0;
  int k=0;
  int c = scanf("%d", &i);
  while(c != EOF)
  {
    for(k=0; k<i; k++)
    {
      printf("#");
    }
    printf("\n");
    c=scanf("%d", &i);
  }
  return 0;
}

