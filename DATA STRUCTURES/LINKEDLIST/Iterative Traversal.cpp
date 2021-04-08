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

void display(Node* head)
{
    Node* p=head;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

}
int main()
{
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);

    head->next=temp1;
    temp1->next=temp2;

    display(head);
    return 0;

}
