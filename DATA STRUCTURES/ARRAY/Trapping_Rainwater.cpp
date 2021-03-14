class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int left[n];
        int right[n];
        int maxv=INT_MIN;
        for(int i=0;i<n;i++){
            maxv=max(arr[i],maxv);
            left[i]=maxv;
        }
        maxv=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxv=max(arr[i],maxv);
            right[i]=maxv;
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(right[i],left[i])-arr[i];
        }
        return water;
        
    }
};
