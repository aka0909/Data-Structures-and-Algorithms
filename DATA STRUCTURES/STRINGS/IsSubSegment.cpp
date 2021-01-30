#include <bits/stdc++.h>
using namespace std;

bool IsSubSegItr(string s1, string s2, int n, int m)   //Time Complexity: O(m+n), Auxiliary Complexity: O(1)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]==s2[j])
            j++;
    }
    if(j==m)
        return true;
    return false;

}

bool IsSubSegRec(string s1, string s2, int n, int m)   //Time Complexity: O(m+n), Auxiliary Complexity: O(m+n)
{
    if(m==0)return true;
    if(n==0)return false;
    if(s1[n-1]==s2[m-1])
        return IsSubSegRec(s1,s2,n-1,m-1);
   else
        return IsSubSegRec(s1,s2,n-1,m);

}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(IsSubSegItr(s1,s2,s1.length(),s2.length()))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    if(IsSubSegRec(s1,s2,s1.length(),s2.length()))cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
}
