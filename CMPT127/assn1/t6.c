#include <stdio.h>

int main()
{
  float i = 0;
  int c = 0;
  int count=0;
  c = scanf("%f\n", &i);
  float least=i;
  float largest=i;
  float total=0;  
  while(c != EOF)
  {
    count=count+1;
    if(i<=least)
    {
      least=i;
    }
    if(i>=largest)
    {
      largest=i;
    }
    total=total+i;
    c = scanf("%f\n", &i);  
  }
  float avg=total/count;
  printf("%.2f %.2f %.2f\n",least, largest, avg);
  return 0;
}

