// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    bool compareLists(struct Node* head1, 
                  struct Node* head2) 
{ 
    struct Node* temp1 = head1; 
    struct Node* temp2 = head2; 

    while (temp1 && temp2)
    { 
        if (temp1->data == temp2->data) 
        { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 

    // Both are empty reurn 1
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 

    // Will reach here when one is NULL 
    // and other is not 
    return 0; 
} 
    void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    
    while (current != NULL) 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 


    bool isPalindrome(Node *head)
    {
        Node *slow_ptr=head,*fast_ptr=head;
        Node *second_half, *prev_of_slow_ptr;
        
        Node *midnode=NULL;
        
        bool res=true;
        
        if(head!=NULL && head->next!=NULL)
        {
            while(fast_ptr && fast_ptr->next)
            {
                fast_ptr=fast_ptr->next->next;
                prev_of_slow_ptr=slow_ptr;
                slow_ptr=slow_ptr->next;
            }
            
            if(fast_ptr!=NULL)
            {
                midnode=slow_ptr;
                slow_ptr=slow_ptr->next;
            }
            second_half=slow_ptr;
            prev_of_slow_ptr->next=NULL;
            reverse(&second_half);
            res=compareLists(head,second_half);
            reverse(&second_half);
            
            if(midnode!=NULL)
            {
                 prev_of_slow_ptr->next=midnode;
                 midnode->next=second_half;
                
            }
            else
              prev_of_slow_ptr->next=second_half;
        }
        return res;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
