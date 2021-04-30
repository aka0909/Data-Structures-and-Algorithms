#include <bits/stdc++.h>
using namespace std;

int floor_of_LogN_basei(int n,int i)
{
    if(n<i)
        return 0;
    else
        return 1+floor_of_LogN_basei((n/i),i);

}
int main()
{
    int n{},i{};
    cin>>n>>i;
    int res=floor_of_LogN_basei(n,i);
    cout<<res;
    return 0;
}
