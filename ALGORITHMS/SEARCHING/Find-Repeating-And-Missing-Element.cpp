class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        unordered_map<int,bool> mp;
        int a[2];
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])==mp.end())
             mp[arr[i]]=true;
            else
             a[0]=arr[i];
        }
        
         for(int i=1;i<=n;i++)
        {
            if(mp.find(i)==mp.end())
             a[1]=i;
        }
        
        int* ptr=a;
        return ptr;
    }
};
