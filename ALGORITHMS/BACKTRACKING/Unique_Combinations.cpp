// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find all possible unique subsets.
    void solve(vector<int>&arr,int i,vector<int>&r,set<vector<int>>&res)
    {
        if(i>=arr.size())
        {
            sort(r.begin(),r.end());
            res.insert(r);
            return;
        }
        r.push_back(arr[i]);
        solve(arr,i+1,r,res);
        r.pop_back();
        solve(arr,i+1,r,res);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here
        vector<int>r;
        sort(arr.begin(),arr.end());
        set<vector<int>>res;
        solve(arr,0,r,res);
        vector<vector<int>>rr;
        for(auto it:res)
        {
           rr.push_back(it);
        }
        return rr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends
