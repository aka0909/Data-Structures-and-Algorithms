//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
  
  
  
    void storeInorder(Node* root, int arr[], int* index_ptr)
    {
        if(root==NULL)return;
        
        storeInorder(root->left,arr,index_ptr);
        
        arr[*index_ptr]=root->data;
        (*index_ptr)++;
        
         storeInorder(root->right,arr,index_ptr);
        
    }
    
    void arrayToBST(Node* root, int arr[], int* index_ptr)
    {
        if(root==NULL)return;
        
        arrayToBST(root->left,arr,index_ptr);
        
        root->data=arr[*index_ptr];
        (*index_ptr)++;
        
        arrayToBST(root->right,arr,index_ptr);
        
    }
  
  
    int countNodes(Node* root)
    {
        if(root==NULL)return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        int n=countNodes(root);
        
        int* arr=new int[n];
        int i=0;
        
        storeInorder(root,arr,&i);
        
        sort(arr,arr+n);
        
        i=0;
        arrayToBST(root,arr,&i);
        
        delete[] arr;
        
        return root;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
