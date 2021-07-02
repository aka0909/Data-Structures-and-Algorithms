class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    bool check(int i, int j,int N)
    {
        if(i<0||i>=N||j<0||j>=N)
         return false;
         return true;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int n=N;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[KnightPos[0]-1][KnightPos[1]-1] = true;
        q.push({KnightPos[0]-1,KnightPos[1]-1});
        int count_steps=0;
        
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i<size; i++) {
                pair<int,int> curr_pos = q.front();
                
                if(curr_pos.first == TargetPos[0]-1 && curr_pos.second==TargetPos[1]-1) return count_steps;
                q.pop();
                
                for (int j= 0; j < 8; j++) {
                    int x = curr_pos.first + dx[j];
                    int y = curr_pos.second + dy[j];
                    if (check(x, y, n) && !visited[x][y]) {
                        visited[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
            count_steps++;
        }
        
        return -1;          
	}
};
