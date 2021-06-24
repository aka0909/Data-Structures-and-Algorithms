#include <bits/stdc++.h>
using namespace std;
 
long long dp[505][505];
 
long long mod=1e9+7;
 
int main() {
 
int a,b;cin>>a>>b;
for(int height=1;height<=a;height++)
{
    for(int width=1;width<=b;width++)
    {
        if(height==width)dp[height][width]=0;
        else
        {
            long long ans=INT_MAX;
            for(int i=1;i<width;i++)
            {
                ans=min(ans,1+dp[height][width-i]+dp[height][i]);
            }
            for(int i=1;i<height;i++)
            {
                ans=min(ans,1+dp[height-i][width]+dp[i][width]);
            }
            dp[height][width]=ans;
        }
    }
}
cout<<dp[a][b]<<endl;
}
