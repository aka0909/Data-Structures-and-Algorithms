// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        int dp[n];
        int ans[n];
        
        dp[n-1]=0;
        ans[n-1]=n-1;
        
        for(int i=n-2;i>=0;i--)
        {
            int curr_len=-1;
            dp[i]=INT_MAX;
            
            for(int j=i;j<n;j++)
            {
                curr_len+=(nums[j]+1);
                 if(curr_len>k)
                  break;
                  
                 int cost;
                 
                 if(j!=n-1)
                    cost=pow(k-curr_len,2)+dp[j+1];
                 
                 else
                    cost=0;
                 
                 if(cost<dp[i])
                 {
                     dp[i]=cost;
                     ans[i]=j;
                 }
            }
        }
        
        return dp[0];
        
        
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
