#include <bits/stdc++.h>
#include <queue>
using namespace std;


struct MyDS
{
    deque<int> dq;
public:
    void insertMin(int x)
    {
        dq.push_front(x);
    }
    void insertMax(int x)
    {
        dq.push_back(x);
    }
    int getMin()
    {
        return dq.front();
    }
    int getMax()
    {
        return dq.back();
    }
    int extractMin()
    {
        int x=dq.front();
        dq.pop_front();
        return x;
    }
    int extractMax()
    {
        int x=dq.back();
        dq.pop_back();
        return x;
    }
};


