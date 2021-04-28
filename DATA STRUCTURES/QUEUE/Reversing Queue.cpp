#include <bits/stdc++.h>
#include <queue>
using namespace std;



void Print(queue<int>& q)
{
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}

void Recur_reverse(queue<int>& q)
{
    if(q.empty())
        return;
    int x=q.front();
    q.pop();
    Recur_reverse(q);
    q.push(x);
}

void Iter_reverse(queue<int>& q)
{
    if(q.empty())
        return;
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();

    }
}

int main()
{
	queue<int> q;
	q.push(12);
	q.push(5);
	q.push(15);
	q.push(20);

	Recur_reverse(q);
	Print(q);
	return 0;
}


