class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    
	    long long ans=0;
	    
	    for(long long i=0;i<n-2;i++)
	    {
	        long long temp=sum-arr[i];
	        long long j=i+1,k=n-1;
	        
	        while(j<k)
	        {
	            if(arr[j]+arr[k]>=temp)
	              k--;
	              
	            else{
	                ans+=(k-j);
	                j++;
	            }
	        }
	        
	    }
	    
	    return ans;
	}
		 

};
