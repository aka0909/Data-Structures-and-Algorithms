class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string res="";
        char curr_ele=S[0];
        res+=curr_ele;
        for(int i=1;i<S.length();i++)
        {
            if(S[i]!=curr_ele)
               {
                   curr_ele=S[i];
                   res+=curr_ele;
                   
                }
        }
        return res;
    }
};
