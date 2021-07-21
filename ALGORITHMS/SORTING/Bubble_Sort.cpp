// C++ program of bubble sort
//Bubble sort is a stable sorting algorithm
//Time Complexity: O(n^2)
//Space Complexity: O(1) as it is sorting inplace


#include <bits/stdc++.h>
using namespace std;


void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void BubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=i+1;j<n-1;j++)
        {
            if(arr[i]>arr[j])
            {swap(arr[i],arr[j]);swapped=true;}
        }
        if(swapped==false)
            break;
    }
}

int main()
{
	int arr[10]={56,90,81,72,60,1,23,49,3,100};
	cout<<"Given Array is: ";
	print(arr,10);
	cout<<endl;
	BubbleSort(arr,10);
	cout<<"Sorted Array is: ";
	print(arr,10);

	return 0;
}
