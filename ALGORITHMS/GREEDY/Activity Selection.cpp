// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool mycmp(pair<int,int> a, pair<int,int> b)
    {
        return(a.second<b.second);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        pair<int,int> arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i].first=start[i];
            arr[i].second=end[i];
        }
        sort(arr,arr+n,mycmp);
        int prev=0;
        int res=1;
        for(int curr=1;curr<n;curr++)
        {
            if(arr[curr].first>arr[prev].second)
            {
                res++;
                prev=curr;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
