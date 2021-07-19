//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        
       unordered_map<ll,vector<ll>> mp;
       int res=0;
       
       ll sum=0;
       
       for(ll i=0;i<n;i++)
       {
           sum+=arr[i];
           
           if(sum==0)
             res++;
             
           if(mp.find(sum)!=mp.end())
           {
               vector<ll> temp=mp[sum];
               res+=temp.size();
           }
          
             mp[sum].push_back(i);
           
       }
       return res;
        
    }
};
