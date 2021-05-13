#include <bits/stdc++.h>
#include <list>
#include <stack>
using namespace std;
#define NIL -1

int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int j=0;j<=n;j++)
        dp[0][j]=j;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
        }
    }
    cout<<dp[m][n]<<endl;

}
