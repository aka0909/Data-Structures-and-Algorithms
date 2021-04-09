#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
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

void Reverse(Node* head)
{
   Node* current=head;
   Node* temp=NULL;
   while(current)
   {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
   }
   if(temp)
    head=temp->prev;

}



Node* insert(int pos,int x,struct Node* head)
{
    Node* p= new Node(x);
    Node* t=head;

    if(pos==1)
    {
        p->next=head;
        head->prev=p;
        head=head->prev;
        return head;
    }
    else
    {
        Node* q=NULL;

        for(int i=1;i<=pos-1 && t->next;i++)
        {
            q=t;
            t=t->next;
        }
        if(t->next==NULL)
        {
            t->next=p;
            p->prev=t;
            return head;
        }
        q->next=p;
        p->prev=q;
        p->next=t;
        t->prev=p;
        return head;
    }

}

int count(struct Node* head)
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
        q->next=NULL;
        head->prev=NULL;
        delete q;
        return head;
    }
    else
    {
        for(i=1;i<=pos-1 && p->next;i++)
        {
            q=p;
            p=p->next;
        }
        if(p->next==NULL)
        {
            q->next=NULL;
            p->prev=NULL;
            delete p;
            return head;
        }
        q->next=p->next;
        (p->next)->prev=q;
        delete p;
        return head;
    }
}

int main()
{
    struct Node* head=new Node(10);
    struct Node* temp1=new Node(20);
    struct Node* temp2=new Node(30);

    head->next=temp1;
    temp1->next=temp2;




    display(head);
    return 0;

}
