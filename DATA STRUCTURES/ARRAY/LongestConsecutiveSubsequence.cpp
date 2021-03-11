class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      int ans = 0, count = 1;
      sort(arr, arr + N);

    vector<int> v;
    v.push_back(arr[0]);

    for (int i = 1; i < N; i++) 
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    for (int i = 1; i < v.size(); i++) 
    {
        if (v[i] == v[i - 1] + 1)
            count++;
        else
            count = 1;

        ans = max(ans, count);
    }
    ans=max(ans,count);
    return ans;
    }
};
