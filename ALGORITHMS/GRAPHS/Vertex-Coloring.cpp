bool isSafe(int i,bool graph[101][101],int color[],int c,int V)
{
    for(int k=0;k<V;k++)
    {
         if (graph[i][k] && c == color[k])
            return false;
    }
    
    return true;
    
}

bool graphColorUtil(bool graph[101][101],int m,int i,int V,int color[])
{
    if(i==V)
     return true;
     
    for(int c=1;c<=m;c++)
    {
        if(isSafe(i,graph,color,c,V))
        {
            color[i]=c;
            
            if(graphColorUtil(graph,m,i+1,V,color))
              return true;
            
            color[i]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V];
    
    memset(color,0,sizeof(color));
    
    if(graphColorUtil(graph,m,0,V,color))
      return true;
      
    return false;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
