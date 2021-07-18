// c++ implementation for printing all paths from top to bottom corner in matrix using BFS
#include <bits/stdc++.h>
using namespace std;

// this structure stores information
// about a particular cell i.e
// path upto that cell and cell's
// coordinates
struct info {
    vector<int> path;
    int x;
    int y;

};

void printAllPaths(vector<vector<int> >& maze)
{
    int n=maze.size();
    int m=maze[0].size();

    queue<info>q;
    q.push({{maze[0][0]},0,0});

    while(!q.empty())
    {
        info p=q.front();
        q.pop();

        if(p.x==n-1 && p.y==m-1)
        {
            for(auto item:p.path)
            {
                cout<<item<<" ";
            }
            cout<<endl;
        }

        if(p.x==n-1)
        {
            vector<int> temp=p.path;
            temp.push_back(maze[p.x][p.y+1]);
            q.push({temp,p.x,p.y+1});
        }
        else if(p.y==m-1)
        {
            vector<int> temp=p.path;
            temp.push_back(maze[p.x+1][p.y]);
            q.push({temp,p.x+1,p.y});
        }
        else
        {
            vector<int> temp=p.path;
            temp.push_back(maze[p.x][p.y+1]);
            q.push({temp,p.x,p.y+1});
            temp.pop_back();
            temp.push_back(maze[p.x+1][p.y]);
            q.push({temp,p.x+1,p.y});
        }

    }

}

// Driver Code
int main()
{
	vector<vector<int> > maze{ { 1, 2, 3 },
							{ 4, 5, 6 },
							{ 7, 8, 9 } };

	printAllPaths(maze);

	return 0;
}
