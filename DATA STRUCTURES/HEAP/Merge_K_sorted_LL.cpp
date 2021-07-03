class Solution{
  public:
    //Function to merge K sorted linked list.
    struct mycmp{
        bool operator()(struct Node* a, struct Node* b)
        {
           return a->data > b->data;
        }
    };
    
    struct Node * mergeKLists(struct Node *arr[], int K)
    {
           Node *head=NULL,*p=NULL;
           priority_queue<Node*,vector<Node*>,mycmp> pq;
           for(int i=0;i<K;i++)
           {
              if(arr[i]!=NULL)
               pq.push(arr[i]);
           }
           while(!pq.empty())
           {
               struct Node* curr=pq.top();
               pq.pop();
               if(curr->next!=NULL)
                 pq.push(curr->next);
               
               if(head==NULL){head=curr;p=head;}
               else{p->next=curr;p=p->next;}
               
           }
           return head;
    }
};
