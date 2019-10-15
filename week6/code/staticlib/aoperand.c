int max(int*a,int length){
	int max = a[0];
     for(int i=0;i<length;i++){
         if(a[i]>max){
	     max=a[i];
	 }
     }
     return max;
}

int sum(int*a,int length){
	int sum=0;
      for(int i=0;i<length;i++){
           sum+=a[i];
      }
      return sum;
}
