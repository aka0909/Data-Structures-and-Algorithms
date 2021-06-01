#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

stack<char> st;

char sorted_insert(char x)
{
    if(st.size()==0)
        st.push(x);
    else if(st.size()>0)
    {
       if(x>=st.top())
        st.push(x);
       else
       {
           char a=st.top();
           st.pop();
           sorted_insert(x);
           st.push(a);
       }

    }
}

void Sort()
{
    if(st.size()>1)
    {
        char x=st.top();
        st.pop();
        Sort();
        sorted_insert(x);
    }
}


int main()
{
    string s;
    st.push('2');s+='2';
    st.push('3');s+='3';
    st.push('1');s+='1';
    st.push('4');s+='4';

    reverse(s.begin(),s.end());

    cout<<"Original Stack"<<endl;
    for(int i=0;i<s.length();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    Sort();
    cout<<"Sorted Stack"<<endl;
    while(!st.empty())
    {
        char a=st.top();
        st.pop();
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;

}
