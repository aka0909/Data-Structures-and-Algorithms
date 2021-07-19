/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

void storeNodes(Node* root, unordered_set<int> &all_nodes, unordered_set<int> &leaf_nodes)
{
    if(root==NULL)return;
    
    all_nodes.insert(root->data);
    
    if(!root->left && !root->right)
      leaf_nodes.insert(root->data);
      
    storeNodes(root->left,all_nodes,leaf_nodes);
    storeNodes(root->right,all_nodes,leaf_nodes);
}
bool isDeadEnd(Node *root)
{
    if(!root)return false;
    
    unordered_set<int> all_nodes,leaf_nodes;
    
    all_nodes.insert(0);
    
    storeNodes(root,all_nodes,leaf_nodes);
    
    for(auto it=leaf_nodes.begin();it!=leaf_nodes.end();it++)
    {
        int x=*it;
        
        if(all_nodes.find(x-1)!=all_nodes.end() && all_nodes.find(x+1)!=all_nodes.end())
          return true;
    }
    
    return false;
}
