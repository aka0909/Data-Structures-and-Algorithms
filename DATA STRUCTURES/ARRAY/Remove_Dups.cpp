#include <bits/stdc++.h>
using namespace std;

int RemoveDups(int arr[],int n)
{
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]!=arr[i])
        {
            arr[res]=arr[i];
            res++;
        }
    }
    return res;

}
int main()
{
    int arr[] = {10, 20, 20, 30, 30, 30}, n = 6;
    cout<<"Before Removal"<<endl;
    for(int i = 0; i < n; i++)
      cout<<arr[i]<<" ";
    cout<<endl;
    n = RemoveDups(arr, n);
    cout<<"After Removal"<<endl;
    for(int i = 0; i < n; i++)
      cout<<arr[i]<<" ";
}
