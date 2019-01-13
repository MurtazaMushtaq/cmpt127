#include <stdio.h>
#include <math.h>

int main()
{
  float i = 0;
  scanf("%f", &i);
  int s = floor(i);
  int n = round(i);
  int l = ceil(i);
  printf("%d %d %d\n", s, n, l);  
  return 0;
}
