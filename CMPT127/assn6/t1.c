#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int intarr_save_binary( intarr_t* ia, const char* filename ){
	if(ia==NULL || ia->data==NULL){
		return 1;
	}	
	FILE* f=fopen(filename, "w");
	if(f==NULL){
		return 2;
	}

	int hdr[1];
	hdr[0]=ia->len;
	if(fwrite(hdr, sizeof(int), 1, f) != 1){
		return 4;
	}

	if(fwrite(ia->data, sizeof(int), ia->len, f) != ia->len){
		return 3;
	}

	fclose(f);
	return 0;
}

intarr_t* intarr_load_binary( const char* filename ){
	FILE* f=fopen(filename, "r");
	if(f==NULL){
		return NULL;
	}
	int hdr[1];
	if(fread(hdr, sizeof(int), 1, f) !=1){
		return NULL;
	}
	
	int length = hdr[0];
	intarr_t* img = intarr_create(length);

	if(fread(img->data, sizeof(int), length, f) != length){
		return NULL;
	}

	fclose(f);
	return img;
}