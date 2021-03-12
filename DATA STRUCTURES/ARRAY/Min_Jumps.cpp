int minJumps(int arr[], int n){
    if(n<=1)
      return 0;
    if(arr[0]==0)
      return -1;
    int steps=arr[0],jump=1,maxreach=arr[0];
    int i=1;
    for(;i<n;i++){
        if(i==n-1)
          return jump;
          
        maxreach=max(maxreach,i+arr[i]);
        
        steps--;
        if(steps==0)
        {
            jump++;
            if(i>=maxreach)
             return -1;
            steps=maxreach-i;
        }
        
    }
    
    return -1;
    
}
