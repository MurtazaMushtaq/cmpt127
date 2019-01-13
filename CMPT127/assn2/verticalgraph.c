#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	unsigned int x;
	int input = scanf("%u", &x);
	int i=0;
	int listofinput[80];

	//this loop makes a list of all the inputted numbers
	while(input != EOF && i !=80){
		listofinput[i]=x;
		i++;
		input=scanf("%u", &x);
	}

	//we need to find the maximum of all the inputted numbers to graph 
	int maximum=listofinput[0];
	for (int y= 0; y<i; ++y)
	{
		if(listofinput[y]>maximum){
			maximum=listofinput[y];
		}
	}

	for (int a = 0; a < maximum; ++a)
	{
		for (int t = 0; t < i; ++t)
		{
			int difference= maximum -listofinput[t];
			if(difference <= a){
				printf("#");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

