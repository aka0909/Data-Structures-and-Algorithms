int minops(string s1,string s2){
    int n1=s1.length(),n2=s2.length();
    if(n1!=n2)
        return -1;
    int count[n1];
    memset(count,0,sizeof(count));
    for(int i=0;i<n1;i++)
        count[s1[i]]++;
    for(int i=0;i<n1;i++)
        count[s2[i]]--;
    for(int i=0;i<n1;i++)
        if(count[i])
            return -1;
    int res=0;
    for(int i=n1-1,j=n1-1;i>=0;){
        while(i>=0 && s1[i]!=s2[j])
        {
            i--;
            res++;
        }
        if(i>=0)
        {
            i--;j--;
        }
    }
    return res;


}
