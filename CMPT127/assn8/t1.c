#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "point_array.h"

void point_array_init( point_array_t* pa ){
	assert(pa!=NULL);
	pa->len=0;
	pa->points=malloc(sizeof(point_t));
	pa->reserved=0;
}

void point_array_reset( point_array_t* pa ){
	assert(pa!=NULL);
	pa->len=0;
	pa->points=NULL;
}

int point_array_append( point_array_t* pa, point_t* p ){
	if(pa==NULL){
		return 1;
	}
	if(p==NULL){
		return 0;
	}
	pa->points=realloc(pa->points, ((pa->len)+1)*sizeof(point_t));
	if(pa->points==NULL){
		return 1;
	}
	pa->points[pa->len].x=p->x;
	pa->points[pa->len].y=p->y;	
	pa->points[pa->len].z=p->z;

	pa->len=(pa->len)+1;

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
	pa->points=realloc(pa->points, (pa->len*sizeof(point_t)));

	return 0;
}
