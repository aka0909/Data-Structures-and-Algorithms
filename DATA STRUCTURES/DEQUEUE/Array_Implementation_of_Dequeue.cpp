#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Dequeue
{
    int* arr;
    int front,size,cap;
    Dequeue(int c)
    {
        arr=new int[c];
        cap=c;
        size=0;
    }
public:
    void deleteFront()
    {
        if(size==0)
            return;
        front=(front+1)%cap;
        size--;
    }
    void deleteRear()
    {
        if(size==0)
            return;
        size--;
    }
    void insertFront(int x)
    {
        if(size==cap)
            return;
        front=(front+cap-1)%cap;
        arr[front]=x;
        size++;
    }
    void insertRear(int x)
    {
        if(size==cap)
            return;
        int new_rear=(front+size)%cap;
        arr[new_rear]=x;
        size++;
    }
    int getFront()
    {
        if(size==0)
            return -1;
        return front;
    }
    int getRear()
    {
        if(size==0)
            return -1;
        return (front+size-1)%cap;
    }
};



