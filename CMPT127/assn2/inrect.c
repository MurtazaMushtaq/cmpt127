#include <stdio.h>

int InRectangle(float pt[2], float rect[4]){
  int counter=0;

  if(rect[0]>rect[2]){
    if(pt[0]>=rect[2] && pt[0]<=rect[0]){
      counter++;
    }
  }
  else{
    if(pt[0]>=rect[0] && pt[0]<=rect[2]){
      counter++;
    }    
  }

  if(rect[1]>rect[3]){
    if(pt[1]>=rect[3] && pt[1]<=rect[1]){
      counter++;
    }
  }
  else{
    if(pt[1]>=rect[1] && pt[1]<=rect[3]){
      counter++;
    }
  }

  if(counter==2){
    return 1;
  }
  else{
    return 0;
  }

}

