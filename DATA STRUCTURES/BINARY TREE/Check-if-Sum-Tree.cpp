/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    bool isLeaf(Node* root)
    {
        if(root==NULL)return false;
        if(!root->left && !root->right)return true;
        
        return false;
    }
    bool isSumTree(Node* root)
    {
        if(root==NULL || isLeaf(root))
         return true;
         
        int ls,rs;
        
        if(!(isSumTree(root->left) && isSumTree(root->right)))
          return false;
        
        if(root->left==NULL)
          ls=0;
        else if(isLeaf(root->left))
          ls=root->left->data;
        else
          ls=2*root->left->data;
        
        if(root->right==NULL)
          rs=0;
        else if(isLeaf(root->right))
          rs=root->right->data;
        else
          rs=2*root->right->data;
          
        return (root->data==ls+rs);
        
    }
};
