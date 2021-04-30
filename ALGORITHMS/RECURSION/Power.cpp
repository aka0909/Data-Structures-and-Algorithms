#include <bits/stdc++.h>
using namespace std;

int power(int n,int p)
{
   if(p==0)
     return 1;
   else
     return n*power(n,p-1);
}
int main()
{
    int x{},p{};
    cin>>x>>p;
    int res=pow(x,p);
    cout<<res;
    return 0;
}
