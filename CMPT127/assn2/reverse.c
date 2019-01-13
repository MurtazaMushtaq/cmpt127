void reverse(int arr[], unsigned int len){
  int i=0;
  int j=(len-1);
  while(i<j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
  } 
}
