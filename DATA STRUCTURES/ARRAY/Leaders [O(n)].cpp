#include <bits/stdc++.h>
using namespace std;

void leaders(int arr[],int n)
{
    cout<<arr[n-1]<<" ";
    int curr=arr[n-1];
    for(int i=n-2;i>=1;i--)
    {
        if(arr[i]>arr[i+1])
        {
            curr=arr[i];
            cout<<arr[i]<<" ";
        }

    }

}
int main()
{
    int arr[] = {7, 10, 4, 10, 6, 5, 2};
    int n = 7;
    leaders(arr, n);
}
