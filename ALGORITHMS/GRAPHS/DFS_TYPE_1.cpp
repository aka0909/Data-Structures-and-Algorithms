//FIRST VERSION OF DFS:
//Given an undirected graph and a source vertex 's' print DFS from the given source.
//NOTE: The whole graph cannot be printed with this code if the graph consists of islands.

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

void DFSRec(vector<int> adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int x:adj[s])
    {
        if(visited[x]==false)
        {
            DFSRec(adj,x,visited);
        }
    }
}

void DFS(vector<int> adj[],int v,int s)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    DFSRec(adj,s,visited);
}
int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    addEdge(adj,5,6);
    DFS(adj,v,0);
    return 0;
}

