#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "point_array.h"

void point_array_init( point_array_t* pa ){
	assert(pa!=NULL);
	pa->len=0;
	pa->points=malloc(100*sizeof(point_t));
	pa->reserved=100;
}

void point_array_reset( point_array_t* pa ){
	assert(pa!=NULL);
	pa->len=0;
	pa->points=malloc(100*sizeof(point_t));
	pa->reserved=100;
}

int point_array_append( point_array_t* pa, point_t* p ){
	if(pa==NULL){
		return 1;
	}
	if(p==NULL){
		return 0;
	}

	pa->len=pa->len +1;
	if(pa->len>=pa->reserved){
		pa->reserved = pa->reserved*2;
		pa->points=realloc(pa->points, pa->reserved*sizeof(point_t));
	}
	pa->points[pa->len-1]=*p;
	return 0;
}

int point_array_remove( point_array_t* pa, unsigned int i ){
	if(pa==NULL){
		return 1;
	}
	if(i>=pa->len){
		return 1;
	}

	pa->points[i].x=pa->points[(pa->len)-1].x;
	pa->points[i].y=pa->points[(pa->len)-1].y;
	pa->points[i].z=pa->points[(pa->len)-1].z;

	pa->len=(pa->len)-1;

	return 0;	
}



