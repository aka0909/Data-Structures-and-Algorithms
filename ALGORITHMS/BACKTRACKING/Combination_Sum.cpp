// { Driver Code Starts



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution 
{
    public:
    void solve(vector<int> &A,int B, vector<vector<int>> &res, vector<int> &r, int i)
    {
        if(B==0)
        {
            res.push_back(r);
            return;
        }
        while(i<A.size() && B-A[i]>=0)
        {
            r.push_back(A[i]);
            solve(A,B-A[i],res,r,i);
            i++;
            r.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int> r;
        vector<vector<int>>res;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        solve(A,B,res,r,0);
        return res;
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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
}	  // } Driver Code Ends
