class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int low=0,n=array.size();
        int high=n-1;
        for(int i=0;i<=high;)
        {
            if(array[i]<a)
            {
                swap(array[i++],array[low++]);
            }
            else if(array[i]>b)
            {
                swap(array[i],array[high--]);
            }
            else
            i++;
        }
        
    }
};
