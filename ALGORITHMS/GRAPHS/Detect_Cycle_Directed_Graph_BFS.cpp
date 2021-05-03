//This is a BFS based solution for detecting cycle in a directed graph.
//Uses the Kahn Algorithm.
//The count will be equal to V in the absence of a cycle.
//The count will be less than V in the presence of a cycle.

#include <bits/stdc++.h>
#include <queue>
using namespace std;


void addEdge(vector<int>adj[],int u, int v)
{
    adj[u].push_back(v);
}

void printGraph(vector<int> adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        for(int x:adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}

bool KahnAlgoDetectCycle(vector<int> adj[],int V)
{
    int cnt=0;
    vector<int> in_degree(V,0);
    for(int u=0;u<V;u++)
    {
        for(int x:adj[u])
            in_degree[x]++;
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int x:adj[u])
        {
            if(--in_degree[x]==0)
                q.push(x);
        }
        cnt++;
    }
    return (cnt!=V);
}



int main()
{
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1);
    addEdge(adj,4, 1);
    addEdge(adj,1, 2);
    addEdge(adj,2, 3);
    addEdge(adj,3, 1);

    if(KahnAlgoDetectCycle(adj,V))
        cout<<"CYCLE FOUND"<<endl;
    else
        cout<<"CYCLE NOT FOUND"<<endl;

	return 0;
}
