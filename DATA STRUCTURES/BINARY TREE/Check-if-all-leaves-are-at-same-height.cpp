class Solution{
  public:
    /*You are required to complete this method*/
    
    bool check(Node *root)
    {
        if (!root)
        return 1;
  
    // create a queue for level order traversal
    queue<Node*> q;
    q.push(root);
  
    int result = INT_MAX;
     int level = 0;
 
    // traverse until the queue is empty
    while (!q.empty()) {
        int size = q.size();
        level += 1;
 
        // traverse for complete level
        while(size > 0){
            Node* temp = q.front();
            q.pop();
         
            // check for left child
            if (temp->left) {
                q.push(temp->left);
 
                // if its leaf node
                if(!temp->left->right && !temp->left->left){
 
                    // if it's first leaf node, then update result
                    if (result == INT_MAX)
                        result = level;
                     
                    // if it's not first leaf node, then compare
                    // the level with level of previous leaf node
                    else if (result != level)
                        return 0;                   
                }
            }
              
             // check for right child
            if (temp->right){
                q.push(temp->right);
 
                // if it's leaf node
                if (!temp->right->left && !temp->right->right)
 
                    // if it's first leaf node till now,
                    // then update the result
                    if (result == INT_MAX)
                        result = level;
                     
                    // if it is not the first leaf node,
                    // then compare the level with level
                    // of previous leaf node
                    else if(result != level)
                        return 0;
                     
               }
               size -= 1;
        }   
    }
     
    return 1;
       
    }
};
