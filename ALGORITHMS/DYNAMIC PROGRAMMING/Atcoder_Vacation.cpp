#include <bits/stdc++.h>
#include <list>
#include <stack>
using namespace std;
#define NIL -1

int main()
{
    int n;cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    int dp[n][3];
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];

  for(int i=1;i<n;i++)
  {
      for(int j=0;j<3;j++)
      {
          if(j==0)
            dp[i][j]=arr[i][j]+max(dp[i-1][1],dp[i-1][2]);
          else if(j==1)
            dp[i][j]=arr[i][j]+max(dp[i-1][0],dp[i-1][2]);
          else
            dp[i][j]=arr[i][j]+max(dp[i-1][0],dp[i-1][1]);
      }
  }
  int res=max(dp[n-1][0],dp[n-1][1]);
  res=max(res,dp[n-1][2]);
  cout<<res<<endl;
}
