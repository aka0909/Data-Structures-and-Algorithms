#include <bits/stdc++.h>
using namespace std;

void Freq(int arr[],int n) //where diff=arr[j]-arr[i] and j>i
{
    int i=1, freq=1;
    while(i<n)
    {
        while(i<n && arr[i-1]==arr[i])
        {
            freq++;
            i++;
        }
        cout<<arr[i - 1] << " " << freq << endl;
        i++;
        freq=1;
    }

}
int main()
{
     int arr[] = {10, 10, 20, 30, 30, 30}, n = 6;

      Freq(arr, n);
}
