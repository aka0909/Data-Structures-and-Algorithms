// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        for(int i=0;i<N;i++)
        {
            dp[N-1][i]=Matrix[N-1][i];
        }
        for(int i=N-2;i>=0;i--)
        {
            for(int j=0;j<N;j++)
            {
                dp[i][j]=0;
                if(j-1>=0)
                {
                    dp[i][j]=max(dp[i+1][j-1],dp[i][j]);
                }
                dp[i][j]=max(dp[i][j],dp[i+1][j]);
                if(j+1<N)
                {
                   dp[i][j]=max(dp[i][j],dp[i+1][j+1]); 
                }
                dp[i][j]+=Matrix[i][j];
            }
        }
        int res=0;
        for(int i=0;i<N;i++)
        {
            res=max(res,dp[0][i]);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
