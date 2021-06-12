// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
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
    
    Node* addOne(Node *head) 
    {
       head=reverse(head);
       Node *res=head;
       Node *temp,*prev=NULL;
       int carry=1,sum=0;
       while(head!=NULL)
       {
           sum=head->data+carry;
           carry=(sum>=10)?1:0;
           sum=sum%10;
           head->data=sum;
           temp=head;
           head=head->next;
       }
       if(carry>0)
       {
           Node *p=new Node(carry);
           temp->next=p;
       }
       return reverse(res);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
