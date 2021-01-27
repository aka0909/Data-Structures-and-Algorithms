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
int main()
{
    int arr[] = {1, 2, 3, 4, 3}, n = 5;
    cout<<MaxEle(arr,5);
}
