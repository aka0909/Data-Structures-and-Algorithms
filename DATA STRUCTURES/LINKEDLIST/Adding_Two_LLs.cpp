// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
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
   
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        
        Node *head=NULL,*p;
        int sum=0,carry=0;
        while(first || second)
        {
            sum=(first?first->data:0)+(second?second->data:0)+carry;
            carry=(sum>=10)?1:0;
            sum=sum%10;
            Node *temp=new Node(sum);
            if(head==NULL)
             {head=temp;p=head;}
            else
            {
                p->next=temp;
                p=temp;
            }
            if(first)
               first=first->next;
            if(second)
               second=second->next;
        }
        if(carry>0)
        {
            p->next=new Node(carry);
        }
        return reverse(head);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
