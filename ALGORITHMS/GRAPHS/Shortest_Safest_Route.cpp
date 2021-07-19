// C++ program to find shortest safe Route in
// the matrix with landmines
#include <bits/stdc++.h>
using namespace std;

#define R 12
#define C 10

struct Key{
	int x,y;
	Key(int i,int j){ x=i;y=j;};
};

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool isValid(int x, int y){

if(x<R && y<C && x>=0 && y>=0)
    return true;
return false;
}


void findShortestPath(int mat[R][C])
{
    int dist[R][C];
    memset(dist,-1,sizeof(dist));

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==0)
            {
                for(int k=0;k<4;k++)
                {
                    if(isValid(i+dir[k][0],j+dir[k][1]))
                        mat[i+dir[k][0]][j+dir[k][1]]=-1;
                }
            }
        }
    }

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
          if(mat[i][j]==-1)
            mat[i][j]=0;
    queue<Key>q;
    for(int i=0;i<R;i++)
    {
        if(mat[i][0]==1)
        {
            q.push(Key(i,0));
            dist[i][0]=0;
        }
    }
    while(!q.empty())
    {
        Key p=q.front();
        q.pop();

        int d=dist[p.x][p.y];

        for(int k=0;k<4;k++)
        {
            int a=p.x+dir[k][0];
            int b=p.y+dir[k][1];

            if(isValid(a,b) && dist[a][b]==-1 && mat[a][b]==1)
            {dist[a][b]=d+1;q.push(Key(a,b));}
        }
    }

    int ans=INT_MAX;

    for(int i=0;i<R;i++)
    {
        if(mat[i][C-1]==1 && dist[i][C-1]!=-1)
        {
            ans=min(ans,dist[i][C-1]);
        }
    }

     // if destination can be reached
    if(ans == INT_MAX)
        cout << "NOT POSSIBLE\n";

    else// if the destination is not reachable
        cout << "Length of shortest safe route is " << ans << endl;


}

// Driver code
int main(){

	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};

	// find shortest path
	findShortestPath(mat);
}

