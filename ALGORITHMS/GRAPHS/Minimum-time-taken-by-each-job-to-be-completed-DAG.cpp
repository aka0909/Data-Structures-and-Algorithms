// C++ program for the Topological Sort based approach 
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

// Adjacency List to store the graph
vector<int> graph[maxN];

// Array to store the in-degree of node
int indegree[maxN];

// Array to store the time in which
// the job i can be done
int job[maxN];

// Function to add directed edge
// between two vertices
void addEdge(int u, int v)
{
    //Adding an edge from u to v;
    graph[u].push_back(v);
    //Increasing indegree of v
    indegree[v]++;
}

// Function to find the minimum time
// needed by each node to get the task
void printOrder(int n, int m)
{
    queue<int>q;

    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            job[i]=1;
        }
    }
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        for(auto adj:graph[cur])
        {
            indegree[adj]--;

            if(indegree[adj]==0)
            {
                q.push(adj);
                job[adj]=job[cur]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<job[i]<<" ";
    }
    cout<<endl;

}

// Driver Code
int main()
{
	// Given Nodes N and edges M
	int n, m;
	n = 10;
	m = 13;

	// Given Directed Edges of graph
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 8);
	addEdge(2, 9);
	addEdge(3, 6);
	addEdge(4, 6);
	addEdge(4, 8);
	addEdge(5, 8);
	addEdge(6, 7);
	addEdge(7, 8);
	addEdge(8, 10);

	// Function Call
	printOrder(n, m);
	return 0;
}
