class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int incl=arr[0];
        int excl=0;
        int excl_new=0;
        int i;
        
        for(i=1;i<n;i++)
        {
            excl_new=max(excl,incl);
            
            incl=excl+arr[i];
            excl=excl_new;
        }
        
        return max(excl,incl);
    }
};
