class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int mp[256] = { 0 };
        int count=0,start=0,ans=INT_MAX;
      
        for(int i=0;i<p.length();i++)
        {
           if(mp[p[i]]==0) 
            count++;
           mp[p[i]]++;
        }
         int i=0,j=0;
        while(j<s.length())
        {
            mp[s[j]]--;
            if(mp[s[j]]==0)
             count--;
             
            while(count==0)
            {
                if(ans>j-i+1)
                {
                    ans=j-i+1;
                    start=i;
                }
                
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    count++;
                i++;
            }
            
            j++;
            
        }
        
        if(ans!=INT_MAX)
         return s.substr(start,ans);
         
        return "-1";
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
