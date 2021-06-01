#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

void nextgreater(int arr[],int n)
{
    stack<int> s;
    vector<int> v;

    s.push(arr[n-1]);
    v.push_back(-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty()&& arr[i]>=s.top())
            s.pop();
        int ng=s.empty()?-1:s.top();
        v.push_back(ng);
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int arr[]={5,15,10,8,6,12,9,18};
    int n=8;
    nextgreater(arr,n);
    return 0;

}
