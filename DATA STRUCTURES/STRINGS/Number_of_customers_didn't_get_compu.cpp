void solve() {
string s;int count;
cin>>count>>s;
int arr[256];
memset(arr,0,sizeof(arr));
int res=0,occupied=0;
for(int i=0;i<s.length();i++)
{
    if(arr[s[i]]==0)
    {
        arr[s[i]]=1;
        if(count>occupied)
        {
            occupied++;
            arr[s[i]]=2;
        }
        else
            res++;
    }
    else{
        if(arr[s[i]]==2)
        {
            occupied--;
        }
        arr[s[i]]=0;
    }
}
cout<<res;
}
