#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char c;
	int i=0;
	char listoftext[5000];
	int count=0;

	//creates an array of all the letters in the inputted text file including spaces and \n
	while((c=getchar())!=EOF){
		listoftext[i]=c;
		i++;
	}

	//loop to go through the array made from 0 to i
	for (int y = 0; y < i; ++y)
	{
		for (int j = 1; j < argc; ++j) //argc is equal to the number of words to be censored
		{
			if(listoftext[y]==*argv[j]){  
				for (int r = 0; r < strlen(argv[j]); ++r)
				{
					if (listoftext[y+r]==*(argv[j]+r))
					{
						count=0; 
					}
					else{
						count=1;
					}
				}
				if(count==0){
					printf("CENSORED");
					y=y+strlen(argv[j]); //since the word is censored, we can just skip the rest of the letters of the word and move on
					continue;
				}

			}
		}
		printf("%c", listoftext[y]);
		
	}

	
}
