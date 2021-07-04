int countRev (string s)
{
    if(s.length()%2==1)
     return -1;
     
    stack<int> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='}' && !st.empty())
        {
            if(st.top()=='{')
              st.pop();
            else
              st.push(s[i]);
        }
        else
          st.push(s[i]);
    }
    
    int red_len=st.size();
    
    int n=0;
    
    while(!st.empty() && st.top()=='{')
    {
        st.pop();
        n++;
    }
    
    return (red_len/2 + n%2);
}
