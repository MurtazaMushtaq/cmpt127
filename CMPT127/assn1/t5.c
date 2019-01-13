#include <stdio.h>
#include <math.h>

int main()
{
  float i = 0;
  int c = 0;
  c = scanf("%f", &i);
  while(c != EOF)
  {
    if(c==1)
    {
      int s = floor(i);
      int n = round(i);
      int l = ceil(i);
      printf("%d %d %d\n", s, n, l);
    }
    else
    {
      printf("scanf error:(%d)\n", c);
    }
    c = scanf("%f", &i);
  }
  printf("Done.\n");  
  return 0;
}

