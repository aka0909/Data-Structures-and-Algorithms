//User function Template for C

// Function to find majority element in the array using Moore's Voting method
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
        
   int res=0,count=1;
   for(int i=1;i<size;i++)
   {
       if(a[res]==a[i])
         count++;
       else
         count--;
       if(count==0)
       {
           res=i;
           count=1;
       }
   }
   
   count=0;
   
   for(int i=0;i<size;i++)
   {
       if(a[res]==a[i])
        count++;
        
      if(count>=(size/2+1))
       return a[res];
   }
   
   return -1;
        
}
