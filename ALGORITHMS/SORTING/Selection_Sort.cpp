// C++ program of Selection sort
//It is an unstable sorting algorithm
//Time Complexity: Theta(n^2);
//Space Complexity:O(1);


#include <bits/stdc++.h>
using namespace std;


void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void SelectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min_idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }
        if(min_idx!=i)
            swap(arr[min_idx],arr[i]);
    }

}
int main()
{
	int arr[10]={56,90,81,72,60,1,23,49,3,100};
	cout<<"Given Array is: ";
	print(arr,10);
	cout<<endl;
	SelectionSort(arr,10);
	cout<<"Sorted Array is: ";
	print(arr,10);

	return 0;
}
