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
        dp[i][0]=0;
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=m,j=n;
    stack<char> st;
    while(i>0 && j>0)
    {
        if(dp[i][j]!=dp[i-1][j] && dp[i][j]!=dp[i][j-1])
            {
                st.push(s1[i-1]);
                i--;j--;continue;
            }
        else if((dp[i][j]==dp[i-1][j] && dp[i][j]!=dp[i][j-1])|| (dp[i][j]==dp[i-1][j] && dp[i][j]==dp[i][j-1]))
        {
             i--;
        }
        else
        {
            j--;
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;

}
