#include <bits/stdc++.h>
using namespace std;

int MaxEle(int arr[],int n)
{
    int maxx=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxx)
            maxx=arr[i];

    }
    return maxx;

}

int SecondLar(int arr[],int n)
{
    int x=MaxEle(arr,n);
    int sl=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>sl && arr[i]!=x)
            sl=arr[i];

    }
    return sl;

}
int main()
{
    int arr[] = {1, 2, 3, 4, 3}, n = 5;
    cout<<SecondLar(arr,5);
}
