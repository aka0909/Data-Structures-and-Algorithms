class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        
        int cnt_left=0,cnt_right=0;
        
        int swap=0,imbalance=0;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='[')
            {
                cnt_left++;
                
                if(imbalance>0)
                {
                    swap+=imbalance;
                    
                    imbalance--;
                }
            }
            
            else
            {
                cnt_right++;
                
                imbalance=cnt_right-cnt_left;
            }
        }
        
        return swap;
    }
};
