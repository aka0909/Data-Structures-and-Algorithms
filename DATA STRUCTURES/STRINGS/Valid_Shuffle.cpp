void solve() {
string s1,s2,result;
cin>>s1>>s2>>result;
if(s1.length()+s2.length()!=result.length())
{
    cout<<"NO";
    return;
}
int i=0,j=0,k=0;
while(k!=result.length())
{
    if(i<s1.length() && s1[i]==result[k])
        i++;
    else if(j<s2.length() && s2[j]==result[k])
        j++;
    else
    {
        cout<<"NO";
        return;
    }
    k++;
}
if(i<s1.length() || j<s2.length())
{
    cout<<"NO";return;
}
cout<<"YES";

}
