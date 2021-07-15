Node* findLCA(Node* root, int n1, int n2){
    if(root==NULL)return root;
    
    if(root->data==n1 || root->data==n2)
         return root;
         
    Node* left=findLCA(root->left,n1,n2);
    Node* right= findLCA(root->right,n1,n2);
    
    if(left!=NULL && right!=NULL)
      return root;
      
    if(left==NULL && right==NULL)
      return NULL;
      
    if(left!=NULL)
      return findLCA(root->left,n1,n2);
    return findLCA(root->right,n1,n2);
    
}

int dist(Node* root, int n, int level)
{
    if(root==NULL)return -1;
    if(root->data==n)return level;
    
    int left=dist(root->left,n,level+1);
    if(left==-1)
      return dist(root->right,n,level+1);
      
    return left;
}
int findDist(Node* root, int a, int b) {
    
    Node* lca= findLCA(root,a,b);
    
    int d1=dist(lca,a,0);
    int d2=dist(lca,b,0);
    
    return d1+d2;
}
