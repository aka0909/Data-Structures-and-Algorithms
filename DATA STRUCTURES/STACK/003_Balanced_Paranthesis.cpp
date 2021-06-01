#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500


bool match(char a,char b)
{
    if((a=='(' && b==')')||(a=='['&& b==']')||(a=='{'&&b=='}'))
        return true;
    return false;

}

bool isbalanced(string s)
{
    stack<char> st;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            st.push(s[i]);
        else
        {
            if(st.empty())
                return false;
            if(!match(st.top(),s[i]))
                return false;
            st.pop();
        }
    }
    return (st.empty());
}
int main()
{
    string s="([]";
    if(isbalanced(s))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
