int identical(int a[], int b[], unsigned int len)
{
  int i=0;
  int j=0;
  while(i<len){
    if(a[i]==b[j]){
      i++;
      j++;
    }
    else{
      return 0;
    }
  }
  return 1;
}
