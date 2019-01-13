#include <stdio.h>

int main()
{
  int c = sizeof(char)*8;
  int uc = sizeof(unsigned char)*8;
  int i = sizeof(int)*8;
  int ui = sizeof(unsigned int)*8;
  int l = sizeof(long)*8;
  int ul = sizeof(unsigned long)*8;
  int f = sizeof(float)*8;
  int d = sizeof(double)*8;
  int ld = sizeof(long double)*8;
  printf("%d %d %d %d %d %d %d %d %d\n", c, uc, i, ui, l, ul, f, d, ld);
  return 0;
}
