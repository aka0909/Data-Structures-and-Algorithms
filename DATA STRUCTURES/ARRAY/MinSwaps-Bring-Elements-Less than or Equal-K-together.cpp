int minSwap(int *arr, int n, int k) {
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
          cnt++;
    }
    int bad=0;
    for(int i=0;i<cnt;i++){
        if(arr[i]>k)
          bad++;
    }
    int res=bad;
    for(int i=0,j=cnt;j<n;i++,j++)
    {
        if(arr[i]>k)
          --bad;
        if(arr[j]>k)
          ++bad;
        res=min(res,bad);
    }
    return res;
}
