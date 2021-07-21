// C++ program of Merge sort
//It is a stable sorting algorithm
//Time Complexity: O(nlogn);
//logn+1 recursive calls and merge process takes theta n time;
//If n is odd then ceil(logn)+1;
//Space Complexity:O(n);
//Quick Sort is better than Merge sort in terms of Space Complexity for arrays.
//For Linked Lists Merge Sort Space Complexity is O(1);


#include <bits/stdc++.h>
using namespace std;


void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void Merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1, n2=r-mid;
    int arr1[n1],arr2[n2];

    for(int i=l;i<=mid;i++)
    {
        arr1[i-l]=arr[i];
    }
    for(int i=mid+1;i<=r;i++)
    {
        arr2[i-(mid+1)]=arr[i];
    }
    int i=0,j=0,idx=l;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[idx]=arr1[i];
            i++;
            idx++;
        }
        else
        {
            arr[idx]=arr2[j];
            idx++;
            j++;
        }
    }
    while(i<n1)
        arr[idx++]=arr1[i++];
    while(j<n2)
        arr[idx++]=arr2[j++];
}

void MergeSort(int arr[],int l,int r)
{
    if(l>=r)
        return;
    int mid=l+(r-l)/2;

    MergeSort(arr,l,mid);
    MergeSort(arr,mid+1,r);

    Merge(arr,l,mid,r);

}
int main()
{
	int arr[10]={56,90,81,72,60,1,23,49,3,100};
	cout<<"Given Array is: ";
	print(arr,10);
	cout<<endl;
	MergeSort(arr,0,9);
	cout<<"Sorted Array is: ";
	print(arr,10);

	return 0;
}
