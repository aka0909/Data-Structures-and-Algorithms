#include <bits/stdc++.h>
using namespace std;


//dp[i][0]= number of ways to add rectangles to the 2*i squares such that the last two squares are united
//dp[i][1]= number of ways to add rectangles to the 2*i squares such that the last two squares are not united

//united=> orange
//not united => green

long long dp[1000002][2];
long long mod=1e9+7;

int main() {

  dp[1][0]=1;dp[1][1]=1;
  for(int i=1;i<1000000;i++)
  {
      dp[i][0]%=mod;
      dp[i][1]%=mod;
      dp[i+1][0]+=2*dp[i][0]%mod; //(orange to orange)
      dp[i+1][0]+=dp[i][1]%mod;  //(orange to green)
      dp[i+1][1]+=4*dp[i][1]%mod;  //(green to green)
      dp[i+1][1]+=dp[i][0]%mod; //(green to orange)
  }
  int t;cin>>t;
  while(t--)
  {
      int n;cin>>n;
      long long res=dp[n][0]+dp[n][1];
      res%=mod;
      cout<<res<<endl;
  }
}
