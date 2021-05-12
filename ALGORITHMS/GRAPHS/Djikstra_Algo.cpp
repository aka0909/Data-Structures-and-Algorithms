#include <bits/stdc++.h>
using namespace std;
#define V 4

vector<int> Djikstra(int arr[V][V],int s)
{
    vector<int> dist(V,INT_MAX);
    vector<bool> visited(V,false);
    dist[s]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=-1;
        for(int j=0;j<V;j++)
          if(visited[j]==false && (u==-1 || dist[j]<dist[u]))
             u=j;
        visited[u]=true;
        for(int j=0;j<V;j++)
        {
            if(visited[j]==false && arr[u][j]!=0)
                dist[j]=min(dist[j],dist[u]+arr[u][j]);
        }
    }
    return dist;

}
/* Driver code*/
int main()
{
	int graph[V][V] = { { 0, 50, 100, 0},
						{ 50, 0, 30, 200 },
						{ 100, 30, 0, 20 },
						{ 0, 200, 20, 0 },};

	for(int x: Djikstra(graph,0)){
	    cout<<x<<" ";
	}

	return 0;
}

