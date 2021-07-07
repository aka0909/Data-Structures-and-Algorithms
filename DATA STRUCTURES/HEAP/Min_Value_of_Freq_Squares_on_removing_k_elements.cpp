class Solution{
public:
    int minValue(string s, int k){
    
        int l = s.length();
        int m[26]={0};
        
        if(k>=l)
         return 0;
         
        for(int i=0;i<l;i++)
        {
            m[s[i]-'a']++;
        }
        
        priority_queue<int> q;
        
        for(int i=0;i<26;i++)
          q.push(m[i]);
        
        while(k--)
        {
            int temp = q.top();
            q.pop();
            
            temp--;
            
            q.push(temp);
        }
        
        int result=0;
        
        while(!q.empty())
        {
            int temp=q.top();
            q.pop();
            result+=temp*temp;
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
