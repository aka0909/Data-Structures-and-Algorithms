class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int k=n/3;
        sort(nums.begin(),nums.end());
        int cnt=1;
        vector<int> res;
        int i;
        for(i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
                cnt++;
            else
            {
                if(cnt>k)
                {
                    res.push_back(nums[i-1]);
                }
                cnt=1;
            }
        }
        if(cnt>k && i==n && find(res.begin(),res.end(),nums[n-1])==res.end())
            res.push_back(nums[n-1]);
        return res;
        
    }
};
