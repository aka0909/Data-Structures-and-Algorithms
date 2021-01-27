#include <bits/stdc++.h>
using namespace std;

bool is_Sorted(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;

}
int main()
{
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    cout<<is_Sorted(arr,5);
}
