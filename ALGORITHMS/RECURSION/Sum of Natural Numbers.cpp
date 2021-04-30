#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
   #Time Complexity:O(n)
   #Auxiliary Space: O(n)
   if(n==1)
     return 1;
   else
     return n+sum(n-1);
}
int main()
{
    int x{};
    cin>>x;
    int res=sum(x);
    cout<<res;
    return 0;
}
