#include <bits/stdc++.h>
#include <list>
#include <stack>
using namespace std;
#define NIL -1

int main()
{
    int n,k;cin>>n>>k;
    vector<int> heights;
    for(int i=0;i<n;i++)
    {
        int h;cin>>h;
        heights.push_back(h);
    }
    int dp[n];
    dp[n-1]=0;
    dp[n-2]=abs(heights[n-1]-heights[n-2]);
    for(int i=n-3;i>=0;i--)
    {
        int min_cost=INT_MAX;
        int temp=k;
        int j=1;
        while(temp-- && (i+j)<n)
        {
            min_cost=min(min_cost,dp[i+j]+abs(heights[i]-heights[i+j]));
            j++;
        }
        dp[i]=min_cost;
    }
    cout<<dp[0]<<endl;
}
