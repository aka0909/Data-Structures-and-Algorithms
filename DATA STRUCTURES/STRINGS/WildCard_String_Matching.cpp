void solve() {
string s1,s2;
cin>>s1>>s2;
ll n1=s1.length();
ll n2=s2.length();
for(ll i=0,j=0;i<n1 && j<n2;)
{
    if(s1[i]==s2[j])
    {
        i++;
        j++;
    }
    else if(s1[i]=='?')
    {
        if(s1[i+1]!=s2[j+1])
        {
            cout<<"NO";
            return;
        }
        else
        {
            i++;
            j++;
        }
    }
    else if(s1[i]=='*')
    {
        i++;
        while(s1[i]!=s2[j] && j<n2)
        {
            j++;
        }
        if(j==n2)
        {
           cout<<"NO";
        }
    }

}
cout<<"YES";
}
