/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    
    string dupSubUtil(Node* root, unordered_set<string> &subtrees)
    {
        string s="";
        
        if(root==NULL)
          return s+'$';
          
        string Lstr=dupSubUtil(root->left,subtrees);
        if(Lstr.compare(s)==0)
          return s;
          
        string Rstr=dupSubUtil(root->right,subtrees);
        if(Rstr.compare(s)==0)
          return s;
          
        s=s+root->data+Lstr+Rstr;
        
        if(s.length()>3 && subtrees.find(s)!=subtrees.end())
          return "";
          
        subtrees.insert(s);
        
        return s;
        
    }
    
    int dupSub(Node *root) {
        
        unordered_set<string> subtrees;
        string str=dupSubUtil(root,subtrees);
        
        int res=(str.compare("") == 0) ?1:0; 
        
        return res;
         
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends
