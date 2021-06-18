#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DQNode{
int data;
DQNode* prev;
DQNode* next;
DQNode(int x){
data=x;
prev=NULL;
next=NULL;
}
};

class Deque{
private:
    DQNode* head;
    DQNode* tail;
public:
    //constructor
    Deque(){
    head=tail=NULL;
    }
    //Checking if empty
    bool isEmpty()
    {
        if(head==NULL)
            return true;
        return false;
    }
    //Finding the size
    int size()
    {
        DQNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    //Insert at the start
    void insert_start(int x){
    DQNode* temp=new DQNode(x);

    if(head==NULL)
    {
        head=tail=temp;
        temp->next=NULL;
        temp->prev=NULL;
        return;
    }
    else{
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
    }

    }
    //Insert at the tail
    void insert_last(int x)
    {
        DQNode* temp=new DQNode(x);

        if(tail==NULL)
        {
            head=tail=temp;
            temp->next=NULL;
            temp->prev=NULL;
            return;
        }
        else{
            temp->next=NULL;
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
    }
    //Removing from the start
    void remove_first()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        DQNode* temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    //Removing from the end
    void remove_last()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        DQNode* temp=tail;
        tail=temp->prev;
        tail->next=NULL;
        delete temp;
    }
    //Display the deque
    void Display()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        DQNode* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        return;

    }

};

//=====================================================================================================================================================

class Stack: public Deque{

public:
    void push(int x)
    {
        insert_last(x);
    }
    void pop(){
        remove_last();
    }

};

class Queue: public Deque{

public:
    void enqueue(int x)
    {
        insert_last(x);
    }
    void dequeue(){
        remove_first();
    }

};
//===================================================================================================================================================
// Driver Code
int main()
{
    // object of Stack
    Stack stk;

    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.Display();

    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.Display();

    // object of Queue
    Queue que;

    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.Display();

    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.Display();

    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}




