//THIRD VERSION OF DFS:
//Count the  number of islands in the given graph

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
    for(int x:adj[s])
    {
        if(visited[x]==false)
        {
            DFSRec(adj,x,visited);
        }
    }
}

void DFS(vector<int> adj[],int v)
{
    bool visited[v];int count=0;
    for(int i=0;i<v;i++)
        visited[i]=false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {DFSRec(adj,i,visited);count++;}
    }
    cout<<count<<endl;
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
    DFS(adj,v);
    return 0;
}

