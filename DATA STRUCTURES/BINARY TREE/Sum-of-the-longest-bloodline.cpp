class Solution
{
public:
    
    
    void findSum(Node *root,int &ans,int &max_height,int level,int sum)
    {
        if(!root){
            if(max_height<level)
            {
                max_height=level;
                ans=sum;
            }
            else if(max_height==level && ans<sum)
             ans=sum;
            return;
        }
        
        findSum(root->left,ans,max_height,level+1,sum+root->data);
        findSum(root->right,ans,max_height,level+1,sum+root->data);
        
    }
    
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {   if (!root)
          return 0;
        int max_height=0;
        int ans=INT_MIN;
        findSum(root,ans,max_height,0,0);
        return ans;
    }
};
