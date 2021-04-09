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
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    while(p!=head);
}

Node* insert(int pos,int x,Node* head)
{
    Node* p=head;
    Node* t=new Node(x);

    if(pos==0)
    {
         t->next=head;
         while(p->next!=head)
         {
             p=p->next;
         }
         p->next=t;
         head=t;
         return head;
    }
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
    return head;
}

Node* Delete(int pos,Node* head)
{
    Node* q=head;
    Node* p=head;
    if(pos==1)
    {
        while(p->next!=head)
         {
             p=p->next;
         }
         if(p==head)
         {
             delete head;
             head=NULL;
             return head;
         }
         head=head->next;
         p->next=head;
         delete q;
         return head;
    }
   for(int i=1;i<pos-1;i++)
   {
       p=p->next;
   }
   q=p->next;
   p->next=q->next;
   delete q;
   return head;

}

void displayR(Node* head) //Recursive Display
{
   static int flag=0;
   Node* p=head;
   if(p!=head || flag==1)
    return;
   if(p==head || flag==0)
      flag=1;

     cout<<p->data<<" ";
     displayR(p->next);
}

int main()
{
    Node *head=new Node(10);
	head->next=new Node(5);
	head->next->next=new Node(20);
	head->next->next->next=new Node(15);
	head->next->next->next->next=head;

	head=insert(1,2,head);
    display(head);
    cout<<endl;
    head=Delete(3,head);
    display(head);
    return 0;

}
