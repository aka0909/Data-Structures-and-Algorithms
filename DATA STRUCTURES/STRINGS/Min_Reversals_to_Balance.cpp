void solve() {
string str;cin>>str;
ll n=str.length();
if(n%2==1)
{
    cout<<-1;
    return;
}
stack<char> s;
for(int i=0;i<n;i++){
    if(str[i]=='}' && !s.empty()){
        if(s.top()=='{')
            s.pop();
        else
            s.push(str[i]);
    }
    else
        s.push(str[i]);
}
ll m=s.size();
ll cnt=0;
while(!s.empty()&& s.top()=='{')
    {
        s.pop();
        cnt++;
    }
cout<<((m)/2+cnt%2);
}
