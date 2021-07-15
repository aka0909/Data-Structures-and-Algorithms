class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
       vector<int> u1,v1,u2,v2;
       
       for(int i=0;i<2*e;i+=2)
       {
           u1.push_back(A[i]);
           v1.push_back(A[i+1]);
       }
       for(int i=0;i<2*e;i+=2)
       {
           u2.push_back(B[i]);
           v2.push_back(B[i+1]);
       }
       
       unordered_map<int,stack<int>> mp;
       
       for(int i=0;i<e;i++)
       {
           mp[u1[i]].push(v1[i]);
       }
       for(int i=0;i<e;i++)
       {
          if(mp[u2[i]].top()!=v2[i])
            return 0;
          mp[u2[i]].pop();
       }
       return 1;
    }
};
