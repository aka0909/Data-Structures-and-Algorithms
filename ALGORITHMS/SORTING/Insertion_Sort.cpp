// C++ program of Insertion sort
//It is a stable sorting algorithm
//Time Complexity: O(n^2) worst case(reversed sort array) and O(n)Best case(already sorted array);
//Space Complexity:O(1);


#include <bits/stdc++.h>
using namespace std;


void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void InsertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}
int main()
{
	int arr[10]={56,90,81,72,60,1,23,49,3,100};
	cout<<"Given Array is: ";
	print(arr,10);
	cout<<endl;
	InsertionSort(arr,10);
	cout<<"Sorted Array is: ";
	print(arr,10);

	return 0;
}
