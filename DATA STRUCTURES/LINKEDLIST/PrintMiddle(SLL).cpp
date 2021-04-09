#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

void display(Node* head) //Iterative Display
{
    Node* p=head;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

}

void displayR(Node* p) //Recursive Display
{
   if(p==NULL)
      return;
   cout<<p->data<<" ";
   displayR(p->next);
}

Node* insert(int pos,int x,struct Node* head)
{
    struct Node* p=head;
    struct Node* t;

    if(pos==0)
    {
        t=new Node(x);
        t->next=head;
        head=t;
        return head;
    }
    else if(pos>0)
    {

        for(int i=0;i<pos-1 && p;i++)
        {
            p=p->next;
        }

        if(p)
        {
            t=new Node(x);
            t->next=p->next;
            p->next=t;
        }
        return head;
    }
}

int count(Node* head)
{
    Node* p=head;
    int cnt=0;
    while(p)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}

Node* Delete(int pos,struct Node* head)
{
    Node* q=NULL;
    Node* p=head;

    int x=-1,i=0;

    if(pos<1 || pos>count(head))
        return head;

    if(pos==1)
    {
        q=head;
        head=head->next;
        delete q;
        return head;
    }
    else
    {
        for(i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        delete q;
        return head;
    }
}

Node* Sortedinsert(int x,Node* head)
{
    Node* p=head;
    Node* t=new Node(x);
    Node* q=NULL;

    if(head==NULL)
        head=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==head)
        {
            t->next=head;
            head=t;
        }
        else
        {
            t->next=p;
            q->next=t;
        }
    }
    return head;
}

void printmiddle(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}
int main()
{
    Node* head=NULL;

    head=Sortedinsert(50,head);
    head=Sortedinsert(40,head);
    head=Sortedinsert(10,head);
    head=Sortedinsert(20,head);
    head=Sortedinsert(30,head);
    head=Sortedinsert(60,head);
    head=Sortedinsert(70,head);
    head=Sortedinsert(100,head);


    display(head);
    cout<<endl;
    printmiddle(head);
    return 0;

}
