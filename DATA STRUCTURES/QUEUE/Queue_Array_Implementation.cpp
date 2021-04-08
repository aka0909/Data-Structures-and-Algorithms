#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int cap;
    int* arr;
public:

    Queue(int n)
    {
        front=0;
        rear=n-1;
        cap=n;
        size=0;
        arr=new int[n];
    }
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    void dequeue();
    void getFront();
    void getBack();
    void Display();

};

bool Queue::isFull()
{
    return (size==cap);
}

bool Queue::isEmpty()
{
    return (size==0);
}
void Queue::enqueue(int x)
{
    if(isFull())
    {
        cout<<"Not able to insert as the queue is full"<<"\n";
        return;
    }
    rear=(front+size-1)%cap;
    arr[rear]=x;
    size++;

}

void Queue::dequeue()
{
    if(isEmpty())
    {
        cout<<"Not able to delete element as the queue is empty"<<"\n";
        return;
    }
    front =(front+1)%cap;
    size--;
}

void Queue::getFront()
{
    if(isEmpty())
        {cout<<"No elements in the queue"<<"\n";return;}
    cout<<arr[front]<<"\n";
}

void Queue::getBack()
{
    if(isEmpty())
        {cout<<"No elements in the queue"<<"\n";return;}
    cout<<arr[rear]<<"\n";
}

void Queue::Display()
{
    int idx=front;
    while(idx<=rear)
    {
        cout<<arr[idx]<<" ";
        idx++;
    }
    cout<<"\n";
}

