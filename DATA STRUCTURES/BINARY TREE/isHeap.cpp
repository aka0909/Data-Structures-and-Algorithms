class Solution {
  public:
    bool isHeap(struct Node * tree)
    {
       if(tree==NULL)return true;
       if(!tree->left && !tree->right) return true;
       bool ans=true;
       if(tree->left==NULL)
         return false;
       if(tree->left)
        ans=ans&&(tree->left->data<=tree->data)&&isHeap(tree->left);
       if(tree->right)
        ans=ans&&(tree->right->data<=tree->data)&&isHeap(tree->right);
      return ans;
        
    }
