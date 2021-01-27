#include <bits/stdc++.h>
using namespace std;

void LeftRot(int arr[],int n)
{
    int temp=arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;

}
int main()
{
    int arr[] = {1, 2, 3, 4, 5}, n = 5;

      cout<<"Before Rotation"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }

       cout<<endl;

       LeftRot(arr, n);

       cout<<"After Rotation"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
}
