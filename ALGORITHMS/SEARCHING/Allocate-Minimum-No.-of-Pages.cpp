//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isFeasible(int arr[],int n,int ans,int k)
    {
        int sum=0,req=1;
        for(int i=0;i<n;i++)
        {
            if(sum+arr[i]>ans)
            {
                req++;
                sum=arr[i];
            }
            else
             sum+=arr[i];
        }
        return (req<=k);
    }
    
    
    int findPages(int arr[], int n, int m) 
    {
        int sum=0,mx=0;
        
        for(int i=0;i<n;i++)
        {
            mx=max(mx,arr[i]);
            sum+=arr[i];
        }
        
        int low=mx,high=sum,res=0;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isFeasible(arr,n,mid,m))
            {
                res=mid;
                high=mid-1;
            }
            else
             low=mid+1;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
