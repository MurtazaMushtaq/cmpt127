/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
 
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  return NULL;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  uint8_t least = array[0];
  for (int i = 1; i < (cols*rows); ++i)
  {
    if(array[i]<least){
      least=array[i];
    }
  }
  return least;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  uint8_t great = array[0];
  for (int i = 1; i < (cols*rows); ++i)
  {
    if(array[i]>great){
      great=array[i];
    }
  }
  return great;
}
// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  for (int i = 0; i < (cols*rows); ++i)
  {
    if(array[i]==pre_color){
      array[i]=post_color;
    }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  int i=0;
  while(i<rows){
    int q=0;
    int r=cols-1;
    while(r>q){
      uint8_t f = get_pixel(array, cols,rows, q, i);
      uint8_t l = get_pixel(array, cols,rows, r, i);
      set_pixel(array, cols, rows, q, i, l);
      set_pixel(array, cols, rows, r, i, f);
      q++;
      r--;
    }
    i++;
  }
}
// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{  
  int i =0;
  while(i<cols){
    int q=0;
    int r=rows-1;
    while(r>q){
      uint8_t f = get_pixel(array, cols,rows, i, q);
      uint8_t l = get_pixel(array, cols,rows, i, r);
      set_pixel(array, cols, rows, i, q, l);
      set_pixel(array, cols, rows, i, r, f);
      q++;
      r--;
    }
    i++;
  }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      uint8_t f = get_pixel(array, cols, rows, j, i);
      if(f==color){
        *x=j;
        *y=i;
        return 1;
      }
    }
  }
  return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
  int q=0;
  while(q<(cols*rows)){
    uint8_t j =0;
    uint8_t k=255;
    while(array[q] != j){
      j++;
      k--;
    }
    array[q]=k;
    q++;
  }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  for (int i = 0; i < (cols*rows); ++i)
  {
    if(array[i]*scale_factor > 255){
      array[i]=255;
    }
    else{
      array[i]=round((array[i]*scale_factor));
    }
  }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  uint8_t maxi = max(array, cols, rows);
  uint8_t mini = min(array, cols, rows);
  uint8_t diff = maxi-mini;
  for (int i = 0; i < (cols*rows); ++i)
  {
    array[i]=round((array[i]-mini)*(255.0/diff));  //got this formula from wikipedia 
  }                                                //https://en.wikipedia.org/wiki/Normalization_(image_processing) 
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  unsigned newcols =cols/2;
  unsigned newrows =rows/2; 
  uint8_t* arr = malloc((newcols*newrows)*sizeof(uint8_t));
  //assert(arr != NULL);

  int i=0;
  while(i<newrows){
    int j=0;
    while(j<newcols){
      uint8_t a,b,c,d, avr;
      a=get_pixel(array, cols, rows, 2*j, 2*i);
      b=get_pixel(array, cols, rows, (2*j+1), 2*i);
      c=get_pixel(array, cols, rows, 2*j, (2*i+1));
      d=get_pixel(array, cols, rows, (2*j+1), (2*i+1));
      float newpixel = ((a+b+c+d)/4.0);
      avr=round(newpixel);
      set_pixel(arr, newcols, newrows, j, i, avr);
      j++;
    }
    i++;
  }
  return arr;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  assert(left<=right);
  assert(top<=bottom);
  assert(right<=cols);
  assert(bottom<=rows);
  assert(left>=0);
  assert(top>=0);

  if((right!=left) && (top!=bottom)){
    for (int i = left; i < right; ++i)
    {
      for (int j = top; j < bottom; ++j)
      {
        set_pixel(array, cols, rows, i, j, color);
      }
    }
  }
  else{
    return;
  }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  assert(left<=right);
  assert(top<=bottom);
  assert(right<=cols);
  assert(bottom<=rows);
  assert(left>=0);
  assert(top>=0);

  unsigned long int sum = 0;
  if (((bottom-top)*(right-left))==0)
  {
    return sum;
  }
  else{
    for (int i = left; i < right; ++i)
    {
      for (int j = top; j < bottom; ++j)
      {
        uint8_t f = get_pixel(array, cols, rows, i, j);
        sum=sum+f;
      }
    }
    return sum; 
  }
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  assert(left<=right);
  assert(top<=bottom);
  assert(right<=cols);
  assert(bottom<=rows);
  assert(left>=0);
  assert(top>=0);

  uint8_t* copy = NULL;
  if (((bottom-top)*(right-left))==0){
    return copy;
  }
  else{
    copy = malloc(((bottom-top)*(right-left))*sizeof(uint8_t));
    if(copy==NULL){
      return copy;
    }
    else{
      for (int i = left; i < right; ++i)
      {
        for (int j = top; j < bottom; ++j)
        {
          uint8_t a = get_pixel(array, cols, rows, i, j);
          set_pixel(copy, (right-left), (bottom-top), (i-left), (j-top), a);
        }
      }
      return copy;
    }
  }

}


