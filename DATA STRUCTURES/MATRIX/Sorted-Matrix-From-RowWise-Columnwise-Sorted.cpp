// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> v;
        vector<vector<int>> res;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
               v.push_back(Mat[i][j]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<N*N;i=i+N)
        {
            vector<int> temp;
            for(int j=i;j<N+i;j++)
               {
                   temp.push_back(v[j]);
               }
             res.push_back(temp);
               
        }
        return res;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends
