// C++ program of Radix sort using Count Sort as sub-routine
//The 2 algorithms are non-comparison based sort algorithms

//COUNT SORT:
//Count sort has a time complexity of O(n+k) where k is the range in which the numbers in the array lie;
//Stable sort if in the second last loop we initialize i=n-1 and decrease i after every loop;
//Is not suitable if say k is the order of n^2 which is where Radix Sort comes into play;
//Not suitable for sorting and array of objects

//RADIX SORT:
//Useful when k is of the order of n^2 or even n^3
//Time Complexity: O((no.of digits in max number)*(n+b)) b=base i.e if decimal then b=10, binary then b=2;
//Space Complexity:O(n);
//Interesting observation: If we decrease the base then no.of digits in max number decreases and n increases


#include <bits/stdc++.h>
using namespace std;


void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void CountSort(int arr[],int n,int exp)
{
    int count[10],output[n];
    memset(count,0,sizeof(count));

    for(int i=0;i<n;i++)
    {
        count[(arr[i]/exp)%10]++;
    }

    for(int i=1;i<=9;i++)
    {
       count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=output[i];

}

void RadixSort(int arr[],int n)
{
    int mx=arr[0];

    for(int i=1;i<n;i++)
        mx=max(mx,arr[i]);
    for(int exp=1;mx/exp>0;exp*=10)
    {
        CountSort(arr,n,exp);
    }


}
int main()
{
	int arr[10]={56,90,81,72,60,1,23,49,3,100};
	cout<<"Given Array is: ";
	print(arr,10);
	cout<<endl;
	RadixSort(arr,10);
	cout<<"Sorted Array is: ";
	print(arr,10);

	return 0;
}
