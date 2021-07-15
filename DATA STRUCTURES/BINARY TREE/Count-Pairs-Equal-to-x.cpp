int countPairs(Node* root1, Node* root2, int x)
{
  if(root1==NULL || root2==NULL)
   return 0;
  
  int ans=countPairs(root1->left,root2,x)+countPairs(root1->right,root2,x);
  
  Node* it=root2;
  
  while(it){
      int diff=x-root1->data;
      if(it->data==diff){
          ans++;break;
      }
      else if(it->data>diff)
       it=it->left;
      else
       it=it->right;
  }
  
  return ans;
}
