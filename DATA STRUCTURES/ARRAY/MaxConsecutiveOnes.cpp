#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


const int R=4,C=4;

int MaximumConsecutiveOnes(int arr[],int n){
int res=0,curr=0;
for(int i=0;i<n;i++){
    if(arr[i]==0)
        curr=0;
    else{
        curr++;
        res=max(res,curr);
    }
}
return res;
}
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 1, 1}, n = 7;
    cout<<MaximumConsecutiveOnes(arr, n);
    return 0;
}
