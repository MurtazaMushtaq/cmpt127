#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int c;
	float counter=0;
	float alphacount[26];
	for (int i = 0; i < 26; ++i)
	{
		alphacount[i]=0;
	}
	char alphabets[27]="abcdefghijklmnopqrstuvwxyz";

	while((c=getchar())!=EOF){
		if (c>96 && c<123 || c>64 && c<91)
		{
			counter=counter+1;
		}
		for (int i = 97; i < 123; ++i)
		{
			if (c==i)
			{
				alphacount[i-97]+=1;
			}
		}
		for (int i = 65; i < 91; ++i)
		{
			if (c==i)
			{
				alphacount[i-65]+=1;
			}
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if (alphacount[i]!=0)
		{
			float freq = alphacount[i]/counter;
			printf("%c %.4f\n", alphabets[i], freq);
		}
	}
}