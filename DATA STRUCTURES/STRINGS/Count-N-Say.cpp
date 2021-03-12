class Solution {
public:
    string countAndSay(int n) {
        string res;
        if(n==1)
          return "1";
        res="1";
        for(int i=2;i<=n;i++)
        {
            res=f(res);
        }
        return res;
    }
    
    string f(string s )
    {
        char curr_char=s[0];
        int cnt=1;
        string res;
        
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!=curr_char)
            {
                res+=cnt+'0';
                res+=curr_char;
                curr_char=s[i];
                cnt=1;
            }
            else
                cnt++;
        }
         res+=cnt+'0';
         res=res+curr_char;
        return res;
    }
};
