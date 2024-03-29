class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        int lis[n];
        lis[0]=1;
        for(int i=1;i<n;i++)
        {
            lis[i]=1;
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1])
                    lis[i]=max(lis[i],lis[j]+1);
            }
        }
        int res=lis[0];
        for(int i=0;i<n;i++)
            res=max(res,lis[i]);
        return res;
        
    }
};
