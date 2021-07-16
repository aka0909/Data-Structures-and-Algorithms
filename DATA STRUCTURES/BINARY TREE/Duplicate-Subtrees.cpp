string inorder(Node* root, unordered_map<string, int>& mp, vector<Node*>&res)
{
    if(!root)return "";
    string str="";
    str+='(';
    str+=inorder(root->left,mp,res);
    str+=to_string(root->data);
    str+=inorder(root->right,mp,res);
    str+=')';
    
    if(mp[str]==1)
     res.push_back(root);
     
    mp[str]++;
    
    return str;
}

vector<Node*> printAllDups(Node* root)
{
    unordered_map<string,int> mp;
    vector<Node*>res;
    inorder(root,mp,res);
    return res;
    
}
