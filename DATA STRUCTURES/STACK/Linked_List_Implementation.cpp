#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500


struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
       data=x;
       next=NULL;
    }
};

struct MyStack
{
    struct Node *head;
    int size;
    MyStack()
    {
        head=NULL;
        size=0;
    }

    void push(int x)
    {
        struct Node *temp= new Node(x);
        temp->next=head;
        head=temp;
        size++;
    }

    void pop()
    {
        if(head==NULL){cout<<"Stack is Empty"<<endl;return;}
        Node *temp=head;
        head=temp->next;
        delete temp;
        size--;
    }

    int stacktop()
    {
        if(head==NULL){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        return head->data;

    }

    int sz(){
        return size;
    }

    bool isEmpty(){
        return head==NULL;
    }


};

int main()
{
    MyStack st;
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
