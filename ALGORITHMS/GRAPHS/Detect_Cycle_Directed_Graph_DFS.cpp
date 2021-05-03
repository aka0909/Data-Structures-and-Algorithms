//DFS BASED SOLUTION FOR DETECTING CYCLE IN A DIRECTED GRAPH


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

bool DFSRec(vector<int> adj[],int s,bool visited[],bool recst[])
{
    visited[s]=1;
    recst[s]=1;
    for(int x:adj[s])
    {
        if(visited[x]==false && DFSRec(adj,x,visited,recst))
            return true;
        else if(recst[x]==true)
            return true;
    }
    recst[s]=0;
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    bool visited[V];
	for(int i=0;i<V; i++)
		visited[i] = false;
	bool recst[V];
	for(int i=0;i<V; i++)
		recst[i] = false;

    for(int i=0;i<V;i++)
    {
        if(visited[i]==0)
            if(DFSRec(adj,i,visited,recst)==true)
              return true;
    }
    return false;

}


int main()
{
    int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,2,1);
	addEdge(adj,2,3);
	addEdge(adj,3,4);
	addEdge(adj,4,5);
	addEdge(adj,5,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0;
}
