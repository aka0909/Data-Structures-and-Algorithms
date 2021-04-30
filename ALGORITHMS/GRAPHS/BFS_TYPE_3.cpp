//THIRD VERSION OF BFS:
//Count the number of islands in graph;

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

void BFS(vector<int> adj[],int s,bool visited[])
{
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

void BFSDis(vector<int> adj[],int v)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i]=false;
    int count=0;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            BFS(adj,i,visited);
            count++;
        }
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
    BFSDis(adj,v);
    return 0;
}

