// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int vis[26];
    vector<int>adj[26];
    
    bool isCycle(int i, vector<bool>&vis1, vector<bool>& onStack)
    {
        vis1[i]=true;
        onStack[i]=true;
        
        for(auto neigh:adj[i])
        {
            if(!vis1[neigh])
            {
                if(isCycle(neigh,vis1,onStack))return true;
            }
            if(onStack[neigh])return true;
        }
        
        onStack[i]=false;
        return false;
    }
    
    void dfs(int i,vector<int> &topoSort)
    {
        vis[i]=true;
        
        for(auto neigh:adj[i])
        {
            if(!vis[neigh])dfs(neigh,topoSort);
        }
        
        topoSort.push_back(i);
    }
    
    string findOrder(string dict[], int N, int K) {
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            
            int idx1=0,idx2=0;
            
            while(idx1<s1.length() && idx2<s2.length())
            {
                char c1=s1[idx1++];
                char c2=s2[idx2++];
                
                if(c1==c2)continue;
                
                adj[c1-'a'].push_back(c2-'a');
                break;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            auto it=unique(adj[i].begin(),adj[i].end());
            adj[i].resize(it-adj[i].begin());
        }
        
        vector<bool> vis1(K,false);
        vector<bool> onStack(K,false);
        
        for(int i=0;i<K;i++)
        {
            if(!vis1[i]){
                if(isCycle(i,vis1,onStack))
                  return "";
            }
        }
        
        memset(vis,false,sizeof(vis));
        vector<int> topoSort;
        
        for(int i=0;i<26;i++)
        {
            if(!vis[i]){
                dfs(i,topoSort);
            }
        }
        
        reverse(topoSort.begin(),topoSort.end());
        
        string res;
        
        for(int i=0;i<topoSort.size();i++)
        {
            char c=topoSort[i]+'a';
            res.push_back(c);
        }
        
        return res;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
