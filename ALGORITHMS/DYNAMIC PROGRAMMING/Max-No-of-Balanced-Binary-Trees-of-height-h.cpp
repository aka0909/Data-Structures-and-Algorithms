class Solution {
  public:
    long long int countBT(int h) { 
       long long dp[h+1];
       long long mod= 1000000007;
       dp[0]=dp[1]=1;
       for(int i=2;i<=h;i++)
       {
           dp[i]=dp[i-1]*((2*dp[i-2])%mod + dp[i-1]%mod)%mod;
           dp[i]%=mod;
       }
       return dp[h];
    }
};
