string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>umap;bool flag=true;
    for(int i=0;i<m;i++)
    {
        umap[a2[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(umap.find(a1[i])!=umap.end())
          umap[a1[i]]--;
    }
    for(int i=0;i<m;i++)
    {
        if(umap[a2[i]]!=0)
        {
            flag=false;
            break;
        }
    }
    if(flag)
     return "Yes";
    return "No";
}
