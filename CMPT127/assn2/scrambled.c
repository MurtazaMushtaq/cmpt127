int scrambled(unsigned int a[], unsigned int b[], unsigned int len){
  int i=0;
  int flag=1;
  while(i<len){
    flag=0;
    int j=0;
    while(j<len){
      if(a[i]==b[j] && flag==0){
        flag=1;
        b[j]=105;
      }
      j++;
    }
    if(flag==0){
      return 0;
    }
    i++;
  }
  return flag;
}
