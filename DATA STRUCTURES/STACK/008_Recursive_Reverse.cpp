#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

stack<char> st;

char insert_at_bottom(char x)
{
    if(st.size()==0)
        st.push(x);
    else if(st.size()>0)
    {
        char c=st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(c);
    }
}

void Reverse()
{
    if(st.size()>0)
    {
        char x=st.top();
        st.pop();
        Reverse();
        insert_at_bottom(x);
    }
}


int main()
{
    string s;
    st.push('1');s+='1';
    st.push('2');s+='2';
    st.push('3');s+='3';
    st.push('4');s+='4';

    reverse(s.begin(),s.end());

    cout<<"Original Stack"<<endl;
    for(int i=0;i<s.length();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    Reverse();
    cout<<"Reversed Stack"<<endl;
    while(!st.empty())
    {
        char a=st.top();
        st.pop();
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;

}
