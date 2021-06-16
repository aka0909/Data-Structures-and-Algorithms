#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int m = 1e3+10;

bool vis[m][m];

bool check(ll i,ll j,ll n,ll m)
{
    if(i>=0 && i<n && j>=0 && j<m)
        return 1;
    return 0;
}

void dfs(ll i, ll j,ll n,ll m)
{
    vis[i][j]=1;
    if(check(i-1,j,n,m)&& !vis[i-1][j])dfs(i-1,j,n,m);
    if(check(i+1,j,n,m)&& !vis[i+1][j])dfs(i+1,j,n,m);
    if(check(i,j-1,n,m)&& !vis[i][j-1])dfs(i,j-1,n,m);
    if(check(i,j+1,n,m)&& !vis[i][j+1])dfs(i,j+1,n,m);

    return;

}


int main()
{
    ll n,m;cin>>n>>m;
    char arr[n][m];
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<m;j++)
        {
            if(s[j]=='.')vis[i][j]=0;
            else vis[i][j]=1;
        }
    }
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
    {
        if(!vis[i][j]){dfs(i,j,n,m);ans++;}
    }
    cout<<ans;

}
