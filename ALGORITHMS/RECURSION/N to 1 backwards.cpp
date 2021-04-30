#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
   #Recursive Solution
   #Time Complexity: O(n)
   #Auxiliary Space: O(n)
   if(n==1)
     cout<<1;
   else
   {
       cout<<n<<" ";
       fun(n-1);
   }
}
int main()
{
    int x{};
    cin>>x;
    fun(x);
    return 0;
}
