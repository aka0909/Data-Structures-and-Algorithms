// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node *head=NULL;
    Node *p,*temp;
    while(head1 || head2)
    {
        if(head1 && head2)
        {
            if(head1->data>head2->data)
            {
                temp= new Node(head2->data);
                if(head==NULL){head=temp;p=temp;}
                else
                {
                    p->next=temp;
                    p=temp;
                }
                head2=head2->next;
                continue;
                
            }
            else if(head2->data>head1->data)
            {
                temp= new Node(head1->data);
                if(head==NULL){head=temp;p=temp;}
                else
                {
                    p->next=temp;
                    p=temp;
                }
                head1=head1->next;
                continue;
            }
            else
            {
                temp=new Node(head1->data);
                if(head==NULL){head=temp;p=temp;}
                else
                {
                    p->next=temp;
                    p=temp;
                }
                temp=new Node(head2->data);
                p->next=temp;
                p=temp;
                head1=head1->next;
                head2=head2->next;
                continue;
            }
        }
        else if(head1 && !head2)
        {
            temp=new Node(head1->data);
            if(head==NULL){head=temp;p=temp;}
                else
                {
                    p->next=temp;
                    p=temp;
                }
            head1=head1->next;
            continue;
            
        }
        else if(head2 && !head1)
        {
            temp=new Node(head2->data);
            if(head==NULL){head=temp;p=temp;}
                else
                {
                    p->next=temp;
                    p=temp;
                }
            head2=head2->next;
            continue;
            
        }
    }
    return head;
}
