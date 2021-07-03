class Solution
{
public:


    void populateNextUtil(Node *root,Node **next_ref)
    {
       if(root)
       {
           populateNextUtil(root->right,next_ref);
           
           root->next=*next_ref;
           
           *next_ref=root;
           
           populateNextUtil(root->left,next_ref);
       }
        
    }


    void populateNext(Node *root)
    {
      Node *next = NULL;
      populateNextUtil(root,&next);
    }
};
