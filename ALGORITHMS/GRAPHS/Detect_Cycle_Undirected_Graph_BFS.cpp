//PROBLEM: DETECT CYCLE IN UNDIRECTED GRAPH
//This solution is BFS based


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

bool BFS(vector<int> adj[],int s,bool visited[],int parent[])
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
                parent[v]=u;
                q.push(v);
            }
            else
            {
                if(v!=parent[u])
                    return true;
            }
        }
    }
    return false;
}

void BFSDis(vector<int> adj[],int v)
{
    bool visited[v];
    int parent[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    for(int i=0;i<v;i++)
        parent[i]=-1;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            if(BFS(adj,i,visited,parent)==true)
            {
                cout<<"YES"<<endl;return;
            }
    }
    cout<<"NO"<<endl;
}
int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    BFSDis(adj,v);
    return 0;
}
