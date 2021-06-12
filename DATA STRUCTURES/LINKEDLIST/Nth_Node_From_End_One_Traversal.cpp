// { Driver Code Starts
//Initial Template for C
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();


 // } Driver Code Ends
//User function Template for C

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(struct Node *head, int n)
{
    struct Node *main_ptr=head,*ref_ptr=head;
    int cnt=0;
    if(head!=NULL)
    {
        while(cnt<n)
        {
            if(ref_ptr==NULL)
              return -1;
            ref_ptr=ref_ptr->next;
            cnt++;
        }
        if(ref_ptr==NULL)
        {
            head=head;
            if(head!=NULL)
              return head->data;
            else
              return -1;
        }
        else
        {
            while(ref_ptr!=NULL)
            {
                main_ptr=main_ptr->next;
                ref_ptr=ref_ptr->next;
            }
            return main_ptr->data;
        }
    }
    else
      return -1;
}

// { Driver Code Starts.



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      int n,k;
      scanf("%d",&n);
      scanf("%d",&k);
      insert(n);
      int res = getNthFromLast(start,k);
      printf("%d\n",res);
    }
    return 0;

}


 void insert(int n)
 {   int value,i;
     struct Node *temp;
     for(i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }
 




  // } Driver Code Ends
