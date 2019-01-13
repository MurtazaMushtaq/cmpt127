
//-----------------------------------------------------------------------------
#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------TASK 1-----------------------
intarr_t* intarr_create( unsigned int len ){
	intarr_t* ptr = malloc(sizeof(intarr_t));
	if(ptr==NULL){
		return NULL;
	}
	else{
		ptr->data= malloc(len*sizeof(int));
		if((ptr->data)==NULL){
			return NULL;
		}
		else{
			ptr->len=len;
			return ptr;	
		}
	}
}

void intarr_destroy( intarr_t* ia ){
	if ((ia==NULL) || ((ia->data) == NULL)){
		return;
	}
	else{
		free(ia->data);
		free(ia);	
	}
}

//-------------------------------------TASK 2---------------------------
intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val ){
	if(ia==NULL){
		return INTARR_BADARRAY;
	}
	if(index>=(ia->len)){
		return INTARR_BADINDEX;
	}
	else{
		ia->data[index]=val;
		return INTARR_OK;
	}
}

intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* i ){
	if(ia==NULL){
		return INTARR_BADARRAY;
	}
	if(index>=(ia->len)){
		return INTARR_BADINDEX;
	}
	else{
		*i=ia->data[index];
		return INTARR_OK;		
	}	
}

//------------------TASK 3---------------------
intarr_t* intarr_copy( const intarr_t* ia ){
	if(ia==NULL){
		return NULL;
	}
	intarr_t* duplicate=malloc(sizeof(intarr_t));
	unsigned int numb = (ia->len)*sizeof(int); 
	duplicate->data=malloc(numb);
	if(duplicate->data==NULL){
		return NULL;
	}
	else{
		memcpy(duplicate->data, ia->data, numb);
		duplicate->len=ia->len;
		return duplicate;	
	}
}

//-------------------------TASK 4--------------------
intarr_result_t intarr_sort( intarr_t* ia ){
	if(ia==NULL){
		return INTARR_BADARRAY;
	}
	for (int i = 0; i < (ia->len); ++i)
	{
		unsigned int least = ia->data[i];
		for (int j = i; j < (ia->len); ++j)
		{
			if ((ia->data[j]) <least){
				least=ia->data[j];
			}
		}
		ia->data[i]=least;
	}
	return INTARR_OK;
}

//------------------------TASK 5----------------
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
	if(ia==NULL){
		return INTARR_BADARRAY;
	}	
	for (int k = 0; k < (ia->len); ++k){

		if(ia->data[k]==target){
			*i=k;
			return INTARR_OK; 
		}
	}
	return INTARR_NOTFOUND;
}

//-------------------TASK 6------------------
intarr_result_t intarr_push( intarr_t* ia, int val ){
	if(ia==NULL){
		return INTARR_BADARRAY;
	}
	unsigned int newsize=(((ia->len)+1)*sizeof(int));
	ia->data=realloc(ia->data, newsize);
	if(ia->data==NULL){
		return INTARR_BADALLOC;
	}
	else{
		ia->data[ia->len]=val;
		ia->len=(ia->len)+1;
		return INTARR_OK;
	}
}

intarr_result_t intarr_pop( intarr_t* ia, int* i ){
	if(ia==NULL){
		return INTARR_BADARRAY;
	}
	if(ia->len==0){
		return INTARR_BADINDEX;
	}
	else{
		unsigned int newsize=(((ia->len)-1)*sizeof(int));
		*i=ia->data[(ia->len)-1];
		ia->data=realloc(ia->data,newsize);
		ia->len=(ia->len)-1;
		return INTARR_OK;
	}
}

//-------------------TASK 7---------------------
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
	if(ia==NULL){
		return INTARR_BADARRAY;
	}
	unsigned int newsize=(newlen*sizeof(int));
	if(newlen<=(ia->len)){
		ia->data=realloc(ia->data, newsize);
		if(ia->data==NULL){
			return INTARR_BADALLOC;
		}
		else{
			ia->len=newlen;
			return INTARR_OK;
		}
	}
	else{
		ia->data=realloc(ia->data, newsize);
		if(ia->data==NULL){
			return INTARR_BADALLOC;
		}
		else{
			for (int i = ia->len; i < newlen; ++i)
			{
				ia->data[i]=0;
			}
			ia->len=newlen;
			return INTARR_OK;
		}
	}
}

//-------------------------------TASK 8--------------
intarr_t* intarr_copy_subarray( intarr_t* ia, unsigned int first, unsigned int last ){
	if(ia==NULL || first<0 || last>=ia->len){
		return NULL;
	}
	unsigned int length= (last-first)+1;
	unsigned int bytes= (length*sizeof(int));
	intarr_t* dupl=intarr_create(length);
	if(dupl==NULL){
		return NULL;
	}
	else{
		memcpy(dupl->data, (ia->data)+first, bytes);	
		return dupl;		
	}
}

//---------------------------------------------------------------------------------------------
