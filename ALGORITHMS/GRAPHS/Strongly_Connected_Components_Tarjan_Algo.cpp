#include <bits/stdc++.h>
#include <list>
#include <stack>
using namespace std;
#define NIL -1

class Graph
{
    int V;
    list<int> *adj;
    void SCCUtil(int u,int disc[],int low[],stack<int> *st, bool stackMember[]);
public:
    void addEdge(int u,int w);
    void SCC();
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
}

void Graph::SCCUtil(int u,int disc[],int low[],stack<int> *st,bool stackMember[])
{
    static int time=0;
    disc[u]=low[u]=++time;
    st->push(u);
    stackMember[u]=true;

    list<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();++i)
    {
        int v=*i;
        if(disc[v]==-1)
        {
            SCCUtil(v,disc,low,st,stackMember);
            low[u]=min(low[u],low[v]);

        }
        else if(stackMember[v])
        {
            low[u]=min(low[u],disc[v]);
        }
    }
    int w=0;
    if(low[u]==disc[u])
    {
        while(st->top()!=u){
        w=(int)st->top();
        cout<<w<<" ";
        stackMember[w]=false;
        st->pop();
        }
        w=(int)st->top();
        cout<<w<<endl;
        stackMember[w]=false;
        st->pop();
    }

}

void Graph::SCC()
{
    bool *stackMember= new bool[V];
    int *disc= new int[V];
    int *low= new int[V];
    stack<int> *st= new stack<int>();

    for(int i=0;i<V;i++)
    {
        stackMember[i]=false;
        disc[i]=NIL;
        low[i]=NIL;
    }
    for(int i=0;i<V;i++)
    {
        if(disc[i]==NIL)
            SCCUtil(i,disc,low,st,stackMember);
    }

}

int main()
{
	cout << "SCCs in the graph \n";
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.SCC();

	return 0;
}


