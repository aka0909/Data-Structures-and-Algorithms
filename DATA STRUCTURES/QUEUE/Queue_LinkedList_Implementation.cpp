#include <bits/stdc++.h>
using namespace std;


struct QNode
{
    int data;
    struct Node* next;
    
    QNode(int x)
    {
        data=x;
        next=NULL;
    }
};

struct Queue{
QNode* front,rear;
Queue()
{
    front=rear=NULL;
}

};

void enqueue(int x)
{
    QNode* p;
    p= new QNode(x);
    if(rear==NULL)
    {
        front=rear=p;
        return;
    }
    rear->next=p;
    rear=p;
}

void dequeue()
{
    if(front==NULL)
        return;
    QNode* p=front;
    front=front->next;
    if(front==NULL)
        rear=NULL;
    delete(p);
}
