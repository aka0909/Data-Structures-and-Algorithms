//BELLMAN FORD ALGORITHM WORKS FOR UNDEIRECTED CONNECTED GRAPHS EVEN IF THEY HAVE NEGATIVE WEIGHTS UNLIKE DJIKSTRA'S ALGORITHM

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,weight;

};
struct Graph
{
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph(int V,int E)
{
    struct Graph* graph= new Graph;
    graph->V=V;
    graph->E=E;
    graph->edge= new Edge[E];
    return graph;
};

void PrintArr(vector<int> dist,int V)
{
    cout<<"Vertex distance from the source: "<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<"     "<<dist[i]<<endl;
    }
}
void BellmanFord(struct Graph* graph,int s)
{
    int V=graph->V;
    int E=graph->E;
    vector<int> dist(V,INT_MAX);
    dist[s]=0;
    for(int cnt=0;cnt<V-1;cnt++)
    {
        for(int j=0;j<E;j++)
        {
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int weight=graph->edge[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
                dist[v]=dist[u]+weight;
        }
    }

    for(int i=0;i<E;i++)
    {
        int u=graph->edge[i].src;
        int v=graph->edge[i].dest;
        int weight=graph->edge[i].weight;
        if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
        {
            cout<<"GRAPHS CONTAINS NEGATIVE WEIGHT CYCLE"<<endl;
            return;
        }
    }

    PrintArr(dist,V);
};

/* Driver code*/
int main()
{
	int V = 4;
	int E = 5;
	struct Graph* graph = createGraph(V, E);

	// add edge 0-1 (or A-B)
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 1;

	// add edge 0-2 (or A-C)
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	// add edge 1-2 (or B-C)
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = -3;

	// add edge 1-3 (or B-D)
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	// add edge 2-3 (or C-D)
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 3;

	BellmanFord(graph, 0);

	return 0;
}
