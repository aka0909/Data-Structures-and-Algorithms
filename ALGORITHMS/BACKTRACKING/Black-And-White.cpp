// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends

long long isSafe(int i,int j,int n,int m)
{
    long long ans=0;
    int x=i-2;
    int y=j-1;
    if((x>=0 && x<n)&&(y>=0 && y<m))ans++;
    x=i-2;y=j+1;
    if((x>=0 && x<n)&&(y>=0 && y<m))ans++;
    x=i+2;y=j+1;
    if((x>=0 && x<n)&&(y>=0 && y<m))ans++;
    x=i+2;y=j-1;
    if((x>=0 && x<n)&&(y>=0 && y<m))ans++;
    x=i+1;y=j+2;
    if((x>=0 && x<n)&&(y>=0 && y<m))ans++;
    x=i+1;y=j-2;
    if((x>=0 && x<n)&&(y>=0 && y<m))ans++;
    x=i-1;y=j+2;
    if((x>=0 && x<n)&&(y>=0 && y<m))ans++;
    x=i+1;y=j-2;
    if((x>=0 && x<n)&&(y>=0 && y<m))ans++;
    return ans;
}
long long solve(int N, int M)
{
    long long res=0;
    long long m=1e9+7;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            res+=((N*M-1)-isSafe(i,j,N,M));
            res=res%m;
        }
    }
    return res%m;
    
}
