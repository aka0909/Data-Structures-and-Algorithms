#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

struct MyStack{
int cap;
int top;
int *arr;

MyStack(int c)
{
   cap=c;
   top=-1;
   arr=new int[cap];
}
void push(int x)
{
    if(top==cap-1)
    {
        cout<<"STACK OVERFLOW"<<endl;return;
    }
    top++;
    arr[top]=x;

}

void pop()
{
    if(top==-1)
    {
        cout<<"STACK UNDERFLOW"<<endl;return;
    }
    top--;

}

int peek(int pos)
{
    if(top-pos+1<0)
    {
        cout<<"INVALID POS"<<endl;return -1;
    }
    return arr[top-pos+1];

}
int stacktop()
{
    if(top==-1)
    {
        cout<<"STACK IS EMPTY"<<endl;return -1;
    }
    else
     return arr[top];
}

bool isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}
bool isfull()
{
    if(top==cap-1)
        return true;
    return false;
}


};






int main()
{
    MyStack st(5);
    st.push(8);
    st.push(9);
    st.push(100);
    st.push(60);
    cout<<st.stacktop()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.stacktop()<<endl;
    return 0;
}
