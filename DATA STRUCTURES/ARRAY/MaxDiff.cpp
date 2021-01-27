#include <bits/stdc++.h>
using namespace std;

int maxDiff(int arr[],int n) //where diff=arr[j]-arr[i] and j>i
{
    int res=arr[1]-arr[0],min_val=arr[0];
    for(int i=1;i<n;i++)
    {
        res=max(res,arr[i]-min_val);
        min_val=min(min_val,arr[i]);
    }
    return res;

}
int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;

      cout<<maxDiff(arr, n);
}
