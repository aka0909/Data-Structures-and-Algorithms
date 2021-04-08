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

void insert(int pos,int x,struct Node* head)
{
    struct Node* p=head;
    struct Node* t;

    if(pos==0)
    {
        t=new Node(x);
        t->next=head;
        head=t;
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

int Delete(int pos,struct Node* head)
{
    Node* q=NULL;
    Node* p=head;

    int x=-1,i=0;

    if(pos<1 || pos>count(head))
        return x;

    if(pos==1)
    {
        q=head;
        head=head->next;
        x=q->data;
        delete q;
        return x;
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}

int main()
{
    struct Node* head=new Node(10);
    struct Node* temp1=new Node(20);
    struct Node* temp2=new Node(30);

    head->next=temp1;
    temp1->next=temp2;

    Delete(2,head);

    display(head);
    return 0;

}
