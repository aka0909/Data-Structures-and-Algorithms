#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

struct kStacks
{
    int *arr;int *top;int *next;
    int freetop;int cap;int k;

    kStacks(int k1,int c)
    {
        cap=c;k=k1;
        freetop=0;
        arr=new int[cap];
        top=new int[k];
        memset(top,-1,sizeof(top));
        next=new int[cap];
        for(int i=0;i<cap-1;i++)
        {
            next[i]=i+1;
        }
        next[cap-1]=-1;
    }
    bool isfull()
    {
        return (freetop==-1);
    }
    bool isempty(int sn)
    {
        return(top[sn]==-1);
    }

    void push(int x,int sn)
    {
        if(isfull())
        {
            cout<<"STACK OVERFLOW"<<endl;return;
        }
        int i=freetop;
        freetop=next[i];
        next[i]=top[sn];
        top[sn]=i;
        arr[i]=x;

    }
    int pop(int sn)
    {
        if(isempty(sn))
        {
            cout<<"STACK UNDERFLOW"<<endl;exit(1);
        }
        int i=top[sn];
        top[sn]=next[i];
        next[i]=freetop;
        freetop=i;
        return arr[i];

    }
};



int main()
{
    int k = 3, n = 10;
    kStacks ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}
