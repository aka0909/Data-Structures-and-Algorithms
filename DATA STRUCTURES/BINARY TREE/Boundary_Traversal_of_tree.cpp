class Solution {
public:



    void getLeftBoundary(Node* root,vector<int> &leftBoundary)
    {
        if(root==NULL)return;
        
        if(root->left){
            leftBoundary.push_back(root->data);
            getLeftBoundary(root->left,leftBoundary);
        }
        else if(root->right){
            leftBoundary.push_back(root->data);
            getLeftBoundary(root->right,leftBoundary);
        }
    }
    
     void getRightBoundary(Node* root,vector<int> &rightBoundary)
    {
        if(root==NULL)return;
        
        if(root->right){
            getRightBoundary(root->right,rightBoundary);
            rightBoundary.push_back(root->data);
        }
        else if(root->left){
            getRightBoundary(root->left,rightBoundary);
            rightBoundary.push_back(root->data);
        }
    }
    
    void getLeaves(Node* root,vector<int> &leaves)
    {
        if(root==NULL)return;
        
        getLeaves(root->left,leaves);
        
        if(root->left==NULL && root->right==NULL)
          leaves.push_back(root->data);
          
        getLeaves(root->right,leaves);
        
    }
    
    
    vector <int> printBoundary(Node *root)
    {
        vector<int>res;
        if(root==NULL)return res;
        
        res.push_back(root->data);
        
        vector<int>leftBoundary;
        getLeftBoundary(root->left,leftBoundary);
        
        vector<int>leaves;
        getLeaves(root->left,leaves);
        getLeaves(root->right,leaves);
        
        vector<int>rightBoundary;
        getRightBoundary(root->right,rightBoundary);
        
        res.insert(res.end(),leftBoundary.begin(),leftBoundary.end());
        res.insert(res.end(),leaves.begin(),leaves.end());
        res.insert(res.end(),rightBoundary.begin(),rightBoundary.end());
        
        return res;
        
        
    }
};
