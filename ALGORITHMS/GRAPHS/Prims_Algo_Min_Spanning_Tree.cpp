#include <iostream>
using namespace std;
#define V 4

int PrimsAlgo(int arr[V][V])
{
    int key[V];
    bool mst[V];
    for(int i=0;i<V;i++)
        key[i]=INT_MAX;
    for(int i=0;i<V;i++)
        mst[i]=false;
    key[0]=0;int res=0;
    for(int i=0;i<V;i++)
    {
        int u=-1;
        if(mst[i]==false &&(u==-1 || key[i]<key[u]))
            u=i;
        res+=key[u];
        for(int j=0;j<V;j++)
        {
            if(arr[u][j]!=0 && mst[j]==false)
                key[j]=min(key[j],arr[u][j]);
        }
    }
    return res;
}
/* Driver code*/
int main()
{
	int graph[V][V] = { { 0, 5, 8, 0},
						{ 5, 0, 10, 15 },
						{ 8, 10, 0, 20 },
						{ 0, 15, 20, 0 },};

	cout<<PrimsAlgo(graph);

	return 0;
}

