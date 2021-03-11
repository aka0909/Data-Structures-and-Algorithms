class Solution{
    public:
    //Complete this function
    bool subArrayExists(int arr[], int n)
    {
        int sum=0;vector<int>v;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            v.push_back(sum);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            if(v[i]==v[i+1] || v[i]==0){
                return true;
            }
        }
        return false;
    }
};
