class Solution {
public:
    
    array<int,2> getCoordinates(int s,int n)
    {
        int row=n-1-(s-1)/n;
        int col=(s-1)%n;
        if((row%2==0 && n%2==0)||(row%2==1 && n%2==1))
            col=n-col-1;
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[n-1][0]=true;
        q.push(1);
        int target=n*n;
        int count_steps=0;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i<size; i++) {
                int curr_pos = q.front();
                
                if(curr_pos == target) return count_steps;
                q.pop();
                for(int d= 1; d<= 6; d++) {
                    if(curr_pos + d > target) break;
                    
                    array<int, 2> cord = getCoordinates(curr_pos + d, n);
                    
                    if(visited[cord[0]][cord[1]]) continue;
                    visited[cord[0]][cord[1]] = true;
                    
                    if(board[cord[0]][cord[1]] != -1)
                        q.push(board[cord[0]][cord[1]]);
                    else 
                        q.push(curr_pos + d);
                }
            }
            count_steps++;
        }
        
        return -1;             
    }
};
