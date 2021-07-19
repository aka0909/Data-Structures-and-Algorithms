// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
       set<vector<int>>s;
       vector<vector<int> > res;
       int n=arr.size();
       sort(arr.begin(),arr.end());
       
       for(int i=0;i<n-3;i++)
       {
           for(int j=i+1;j<n-2;j++)
           {
               int sum=k-arr[i]-arr[j];
               int start=j+1,end=n-1;
               while(start<end)
               {
                   if(arr[start]+arr[end]>sum)
                     end--;
                   else if(arr[start]+arr[end]<sum)
                     start++;
                   else
                   {
                       vector<int>temp;
                       temp.push_back(arr[i]);
                       temp.push_back(arr[j]);
                       temp.push_back(arr[start]);
                       temp.push_back(arr[end]);
                       
                       if(s.find(temp)==s.end())
                       {
                           s.insert(temp);
                           res.push_back(temp);
                       }
                       
                       end--;start++;
                         
                   }
               }
           }
       }
       
       return res;
    }
};
