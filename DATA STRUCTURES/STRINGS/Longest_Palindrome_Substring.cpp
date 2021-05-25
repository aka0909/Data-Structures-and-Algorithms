//TC: O(n^2)
// AS: O(1)


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int maxlength=1;
        int start=0;
        int n=S.length();
        int low,high;
        
        for(int i=1;i<n;i++)
        {
            //EVEN LENGTH PALINDROMES:
            low=i-1;
            high=i;
            while(low>=0 && high<n && S[low]==S[high])
            {
                if(high-low+1 > maxlength){
                    start=low;
                    maxlength=high-low+1;
                }
                --low;++high;
            }
            // ODD LENGTH PALINDROMES:
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && S[low]==S[high])
            {
                if(high-low+1 > maxlength){
                    start=low;
                    maxlength=high-low+1;
                }
                --low;++high;
            }
            
        }
        
        return S.substr(start,maxlength);
        
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
