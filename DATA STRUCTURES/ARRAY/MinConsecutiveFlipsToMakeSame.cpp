#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


const int R=4,C=4;

int printGroups(int arr[],int n){
for(int i=1;i<n;i++){
    if(arr[i]!=arr[i-1])
    {
        if(arr[i]!=arr[0])
            cout<<"From "<<i<<" to";
        else
            cout<<" "<<i-1<<endl;
    }
}
if(arr[n-1]!=arr[0])
    cout<<" "<<n-1<<endl;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0}, n = 9;
    printGroups(arr, n);
    return 0;
}
