#include <bits/stdc++.h>
#include <list>
using namespace std;
#define NIL -1

class Graph
{
    int V;
    list<int> *adj;
    void APUtil(int u,bool visited[],int disc[],int low[],int parent[],bool ap[]);
public:
    void addEdge(int u,int w);
    void AP();
    Graph(int V);
};
Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}
void Graph::addEdge(int u,int w)
{
    adj[u].push_back(w);
    adj[w].push_back(u);
}

void Graph::APUtil (int u,bool visited[],int disc[],int low[],int parent[],bool ap[])
{
    static int time=0;
    int children=0;
    visited[u]=true;
    disc[u]=low[u]=++time;

    list<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();++i)
    {
        int v=*i;
        if(!visited[v])
        {
            children++;
            parent[v]=u;
            APUtil(v,visited,disc,low,parent,ap);

            low[u]=min(low[u],low[v]);

            if(parent[u]==NIL && children>1)
                ap[u]=true;
            if(parent[u]!=NIL && low[v]>=disc[u])
                ap[u]=true;

        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],disc[v]);
        }
    }

}

void Graph::AP()
{
    bool *visited= new bool[V];
    int *disc= new int[V];
    int *low= new int[V];
    int *parent= new int[V];
    bool *ap= new bool[V];

    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        parent[i]=NIL;
        ap[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            APUtil(i,visited,disc,low,parent,ap);
    }
    for(int i=0;i<V;i++)
    {
        if(ap[i])
            cout<<i<<" ";
    }

}

int main()
{
	cout << "Articulation points in first graph \n";
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.AP();

	return 0;
}


