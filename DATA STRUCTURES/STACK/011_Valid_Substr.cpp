// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int left=0,right=0,res=INT_MIN;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
              left++;
            if(s[i]==')')
              right++;
            if(left==right)
            {
               res=max(res,2*left); 
            }
            if(right>left)
            {
                left=right=0;
            }
        }
        left=right=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
              left++;
            if(s[i]==')')
              right++;
            if(left==right)
            {
               res=max(res,2*left); 
            }
            if(left>right)
            {
                left=right=0;
            }
        }
        left=right=0;
        if(res==INT_MIN)
          return 0;
        return res;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
