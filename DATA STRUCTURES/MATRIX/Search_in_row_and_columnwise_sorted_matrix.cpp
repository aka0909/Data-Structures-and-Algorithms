#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


const int R=4,C=4;

void search(int arr[R][C],int x)
{
    int i=0,j=C-1;
    while(i<R && j>=0)
    {
        if(arr[i][j]==x)
        {
            cout<<"Found at ("<<i<<","<<j<<")";
            return;
        }
        else if(arr[i][j]>x)
            j--;
        else
            i++;
    }
    cout<<"Not Found";



}
int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {9, 10, 11, 12},
				   {13, 14, 15, 16}};
    int x=14;
    search(arr,x);
    return 0;
}
