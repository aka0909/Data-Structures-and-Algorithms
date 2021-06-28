#include <bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

int main() {
 int n,k;
 cin>>n>>k;
 int arr[n];
 for(int i=0;i<n;i++)
    cin>>arr[i];

 int prod[k+1][n+1];
 memset(prod, 0, sizeof(prod));

 for(int i=1;i<=k;i++)
 {
     for(int j=1;j<=n;j++)
     {
        prod[i][j]+=prod[i][j-1];

         if(arr[j-1]<=i && arr[j-1]>0)
            prod[i][j]+=prod[i/arr[j-1]][j-1]+1;//Added one to include arr[j-1] itself too in the count if it is less than equal to i;
     }
 }
 cout<<prod[k][n]<<endl;
}
