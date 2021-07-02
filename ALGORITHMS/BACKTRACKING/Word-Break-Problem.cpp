class Solution{
public:


    bool check( string prefix,unordered_set<string> &diction)
    {
        if(diction.find(prefix)!=diction.end())
          return true;
        else
          return false;
    }
    
    void wordBreakUtil(string s, int n, unordered_set<string> &diction, vector<string> &res,string result)
    {
        for(int i=1;i<=n;i++)
        {
            string prefix=s.substr(0,i);
            
            if(check(prefix,diction))
            {
                if(i==n)
                {
                    result+=prefix;
                    res.push_back(result);
                    return;
                }
                wordBreakUtil(s.substr(i,n-i),n-i,diction,res,result+prefix+" ");
            }
        }
        
        
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> diction;
        for(int i=0;i<n;i++)
          diction.insert(dict[i]);
          
        vector<string> res;
          
        wordBreakUtil(s,s.size(),diction,res,"");
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
