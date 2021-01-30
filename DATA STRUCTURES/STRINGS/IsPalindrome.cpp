#include <bits/stdc++.h>
using namespace std;

bool IsPal_thetaN(string s)
{
    string rev=s;
    reverse(rev.begin(),rev.end());
    return(s==rev);

}

bool IsPal_OmegaNBetter(string s)
{
    int start=0,end=s.length()-1;
    while(start<end)
    {
        if(s[start]!=s[end])
            return false;
        start++;
        end--;
    }
    return true;

}
int main()
{
    string s;
    cin>>s;
    if(IsPal_OmegaNBetter(s))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    if(IsPal_thetaN(s))cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
}

