#include <bits/stdc++.h>
using namespace std;

int power(int n,int p)
{
   if(p==0)
     return 1;
   else
     return n*power(n,p-1);
}

int fact(int n)
{
   if(n==1 || n==0)
     return 1;
   else
     return n*fact(n-1);
}

float Taylor(int x,int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 1+x;
    else
    {
        float a=(pow(x,n-1))/(fact(n-1));
        return a+Taylor(x,n-1);
    }

}
 main()
{
    int x{},p{};
    cin>>x>>p;
    float res=Taylor(x,p);
    cout<<res;
}
