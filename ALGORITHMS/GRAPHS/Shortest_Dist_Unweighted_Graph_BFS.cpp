//PROBLEM: SHORTEST DISTANCE IN UNDIRECTED, UNWEIGHTED GRAPH
//Given source find distances from the source to vertices in increasing order of distances
//We use the BFS algorithm for this as BFS first visits all adjacent vertices to a source


#include <bits/stdc++.h>
#include <queue>
using namespace std;


void addEdge(vector<int>adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int x:adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}

void BFS(vector<int> adj[],int v,int s)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i]=false;
    int dist[v]={INT_MAX};
    queue<int>q;
    visited[s]=true;
    dist[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<dist[u]<<" ";
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int v=4;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    BFS(adj,v,0);
    return 0;
}
