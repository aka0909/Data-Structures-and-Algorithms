#include <bits/stdc++.h>
using namespace std;

void Reverse(int arr[],int low, int high)
{
    while(low<high)
    {
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
    }

}

void leftRotate(int arr[],int n,int d)
{
    Reverse(arr,0,d-1);
    Reverse(arr,d,n-1);
    Reverse(arr,0,n-1);
}
int main()
{
      int arr[] = {1, 2, 3, 4, 5}, n = 5, d = 2;

      cout<<"Before Rotation"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }

       cout<<endl;

       leftRotate(arr, n, d);

       cout<<"After Rotation"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
}
