class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int*arr, int n) {
	    long long min_val=arr[0],max_val=arr[0],maxprod=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<0)
	          swap(min_val,max_val);
	        max_val=max((long long)arr[i],max_val*(long long)arr[i]);
	        min_val=min((long long)arr[i],min_val*(long long)arr[i]);
	        
	        maxprod=max(maxprod,max_val);
	    }
	    return maxprod;
	}
};
