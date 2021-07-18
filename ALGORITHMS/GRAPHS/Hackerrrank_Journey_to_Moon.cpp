void dfs(int u,vector<bool> &vis)
 {
     vis[u]=true;
     members++;
     
     for(auto next:adj[u])
     {
         if(!vis[next])
         {
             dfs(next,vis);
         }
     }
 }

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    
    long long ans=n*(n-1)/2;
    vector<bool> vis(n,false);
    for(int i=0;i<astronaut.size();i++)
    {
        int u=astronaut[i][0];
        int v=astronaut[i][1];
        
        adj[u].push_back(v);adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            members=0;
            dfs(i,vis);
            ans-=1LL*members*(members-1)/2;
        }
        
    }
    return ans; 
}
