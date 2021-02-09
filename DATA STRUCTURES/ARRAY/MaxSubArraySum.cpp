#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


const int R=4,C=4;

int MaxSubArraySum(int arr[],int n){   //KADANE'S ALGORITHM: T.C: O(n); A.S: O(1) 
int res=arr[0], maxEnding=arr[0];
for(int i=1;i<n;i++){
    maxEnding=max(maxEnding+arr[i],arr[i]);
    res=max(res,maxEnding);
}
return res;
}

int main()
{
    int arr[] = {1, -2, 3, -1, 2}, n = 5;
    cout<<MaxSubArraySum(arr, n);
    return 0;
}
