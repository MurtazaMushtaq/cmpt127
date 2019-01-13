#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int intarr_save_json( intarr_t* ia, const char* filename ){
	if(ia==NULL || ia->data==NULL){
		return 1;
	}

	FILE* f = fopen(filename, "w");
	if(f==NULL){
		return 1;
	}

	fprintf(f, "[ ");

	if(ia->len==0){
		fprintf(f, "]");
		fclose(f);
		return 0;
	}

	for (int i=0; i < (ia->len); ++i)
	{
		if(i==0){
			fprintf(f, "%d", ia->data[i]);
		}
		else{
			fprintf(f, ", %d", ia->data[i]);
		}
	}

	fprintf(f, " ]");
	fclose(f);
	return 0;
}


intarr_t* intarr_load_json( const char* filename )
{
    FILE* f = fopen (filename, "r");
    if (f==NULL){
        return NULL;
    }

    char c;
    int length=0;

    while (!feof(f))    
    {
        c = getc(f);
        if (c == ','){
            length++;
        }
    }
    fseek(f,0,SEEK_SET);

    length=length+1;
    if(length==1){
        intarr_t* img = malloc(sizeof(intarr_t));
        img->data=NULL;
        img->len=0;
        return img;
    }
    intarr_t* img = intarr_create(length);
    int i=0;
    int j;    
    while(i<length){
        while (fscanf(f, "%d",&j)!=1){
            fseek(f, 1, SEEK_CUR);    
        }
        img->data[i]=j;
        i++;
    }
    fseek(f,0,SEEK_END);

    fclose(f);
    return img;
}


