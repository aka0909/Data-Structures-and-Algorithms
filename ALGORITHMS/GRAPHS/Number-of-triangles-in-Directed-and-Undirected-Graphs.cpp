//Advantages:
//1.No need to calculate trace
//2.No matrix multiplication required
//3.No auxiliary matrices required hence space optimized
//4.Works for directed graphs

//Disadvantages:
//Time Complexity: O(n^3) and cannot be reduced

/////////////////////////////////////////////////////////////////////

// C++ program to count triangles
// in a graph. The program is for
// adjacency matrix representation
// of the graph.
#include<bits/stdc++.h>

// Number of vertices in the graph
#define V 4

using namespace std;

// function to calculate the
// number of triangles in a
// simple directed/undirected
// graph. isDirected is true if
// the graph is directed, its
// false otherwise
int countTriangle(int graph[V][V],
				bool isDirected)
{
	int triangles=0;

	for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
          for(int k=0;k<V;k++)
            if(graph[i][j]&&graph[j][k]&&graph[k][i])
               triangles++;
    isDirected?triangles/=3:triangles/=6;
    return triangles;
}

//driver function to check the program
int main()
{
	// Create adjacency matrix
	// of an undirected graph
	int graph[][V] = { {0, 1, 1, 0},
					{1, 0, 1, 1},
					{1, 1, 0, 1},
					{0, 1, 1, 0}
					};

	// Create adjacency matrix
	// of a directed graph
	int digraph[][V] = { {0, 0, 1, 0},
						{1, 0, 0, 1},
						{0, 1, 0, 0},
						{0, 0, 1, 0}
					};

	cout << "The Number of triangles in undirected graph : "
		<< countTriangle(graph, false);
	cout << "\n\nThe Number of triangles in directed graph : "
		<< countTriangle(digraph, true);

	return 0;
}
