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

Node* Reverse(Node* head)
{
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

Node* RecReverse(Node* head) //METHOD 1
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* rest_head=RecReverse(head->next);
    Node* rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

bool DetectLoop(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

Node* KReverse(int k, Node* head)
{
    Node* next=NULL;
    Node* prev=NULL;
    Node* curr=head;

    int cnt=0;

    while(curr!=NULL && cnt<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }

    if(curr!=NULL)
    {
        Node* rest_head=KReverse(k,next);
        head->next=rest_head;
    }
    return prev;

}

int main()
{
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	head->next->next->next->next->next=new Node(60);
	head->next->next->next->next->next->next=new Node(70);
	display(head);
	cout<<endl;
	head=KReverse(3,head);
	display(head);
	return 0;

}
