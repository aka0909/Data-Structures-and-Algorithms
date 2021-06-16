#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;cin>>n;
    char arr[n][n];
    ll dp[n][n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            dp[i][j]=0;
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='*')
                dp[i][j]=-1;
        }
    }
    if(arr[n-1][n-1]=='*')
    {
        cout<<0<<endl;
        return 0;
    }
    for(ll i=1;i<n;i++)
    {
        if(dp[i][0]!=-1)
            dp[i][0]=1;
        if(dp[0][i]!=-1)
            dp[0][i]=1;
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<n;j++)
        {
            if(dp[i][j]!=-1)
            {if(i-1>=0 && dp[i-1][j]!=-1)
                dp[i][j]+=dp[i-1][j];
            if(j-1>=0 && dp[i][j-1]!=-1)
                dp[i][j]+=dp[i][j-1];
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;

    return 0;
}
