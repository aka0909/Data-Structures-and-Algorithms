//IMPORTANT
//===============================================
// remember: vector<string> &res and string &path
//===============================================
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    #define MAX 5
    
    bool isSafe(int i,int j,bool visited[][MAX],vector<vector<int>> &m,int &n)
    {
        if(i==-1||i==n||j==-1||j==n||visited[i][j]||m[i][j]==0)
          return false;
        return true;
        
    }
    
    void pathUtil(int i,int j,vector<vector<int>> &m,string &path,vector<string> &res,bool visited[][MAX],int &n){
        if(i==-1||i==n||j==-1||j==n||visited[i][j]||m[i][j]==0)
          return;
        if(i==n-1 && j==n-1)
        {
            res.push_back(path);
            return;
        }
        visited[i][j]=true;
        
        if(isSafe(i+1,j,visited,m,n))
        {
            path+='D';
            pathUtil(i+1,j,m,path,res,visited,n);
            path.pop_back();
        }
        if(isSafe(i,j-1,visited,m,n))
        {
            path+='L';
            pathUtil(i,j-1,m,path,res,visited,n);
            path.pop_back();
        }
        if(isSafe(i,j+1,visited,m,n))
        {
            path+='R';
            pathUtil(i,j+1,m,path,res,visited,n);
            path.pop_back();
        }
        
        if(isSafe(i-1,j,visited,m,n))
        {
            path+='U';
            pathUtil(i-1,j,m,path,res,visited,n);
            path.pop_back();
        }
        
        
        visited[i][j]=false;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        bool visited[n][MAX];
        memset(visited, false, sizeof(visited));
        string path;
        pathUtil(0,0,m,path,res,visited,n);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
