#include <bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

int main() {

int n;cin>>n;
int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];
int mew[n]; //min sum ending with arr[i];
mew[0]=arr[0];
for(int i=1;i<n;i++)
{
    mew[i]=min(arr[i],arr[i]+mew[i-1]);
}
int res=INT_MAX;
for(int i=0;i<n;i++)
{
    res=min(res,mew[i]);
}
cout<<res<<endl;
}
