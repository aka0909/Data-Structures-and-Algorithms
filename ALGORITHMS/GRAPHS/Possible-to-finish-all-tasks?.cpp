// A BFS based solution to check if we can finish
// all tasks or not. This solution is mainly based
// on Kahn's algorithm.
#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int> > make_graph(int numTasks,vector<pair<int, int> >& prerequisites)
{
    vector<unordered_set<int>> graph(numTasks);
    for(auto pre:prerequisites){
        graph[pre.second].insert(pre.first);
    }
    return graph;
}

// Finds in-degree of every vertex
vector<int> compute_indegree(vector<unordered_set<int> >& graph)
{
    vector<int> indegrees(graph.size(),0);
    for(auto neighbours:graph)
    {
        for(auto neigh:neighbours)
        {
            indegrees[neigh]++;
        }
    }
    return indegrees;

}

// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites)
{
    vector<unordered_set<int>> graph=make_graph(numTasks,prerequisites);
    vector<int> indegrees=compute_indegree(graph);
    for(int i=0;i<numTasks;i++)
    {
        int j=0;
        for(;j<numTasks;j++)
            if(!indegrees[j])
              break;
        if(j==numTasks)
            return false;
        else
        {
            indegrees[j]=-1;
            for(auto neigh:graph[j])
                indegrees[neigh]--;
        }
    }
    return true;

}

int main()
{
	int numTasks = 4;
	vector<pair<int, int> > prerequisites;
	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));
	if (canFinish(numTasks, prerequisites)) {
		cout << "Possible to finish all tasks";
	}
	else {
		cout << "Impossible to finish all tasks";
	}

	return 0;
}
