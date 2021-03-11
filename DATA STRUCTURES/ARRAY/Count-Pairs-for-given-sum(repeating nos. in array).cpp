class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
           m[arr[i]]++;
        int twice_cnt=0;
        for(int i=0;i<n;i++)
        {
            twice_cnt+=m[k-arr[i]];
            
            if(k-arr[i]==arr[i])
              twice_cnt--;
        }
        return twice_cnt/2;
    }
};
