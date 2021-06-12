// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverse(Node *head)
    {
        Node *current=head;
        Node *prev=NULL,*next;
        while(current)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    
    Node *compute(Node *head)
    {
        head=reverse(head);
        Node *p=head,*prev=NULL;
        int val=INT_MIN;
        while(p)
        {
            if(p->data>=val)
            {
                val=p->data;
                prev=p;
                p=p->next;
            }
            else
            {
                if(p->next==NULL)
                {
                    prev->next=NULL;
                    Node *temp=p;
                    delete(temp);
                    p=NULL;
                }
                else
                {
                    prev->next=p->next;
                    delete(p);
                    p=prev->next;
                }
                
            }
            
            
        }
        return reverse(head);
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends
