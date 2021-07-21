// C++ program of Heap Sort
//It is an improvement over Selection sort

//The time complexities of Heap,Merge and Quick maybe equal on the surface but due to hidden constants heap sort takes more time
//as compared to Merge and Quick sort algos. Which is why it is used in hybrid sorting algorithms such as Intro-Sort
//(used in C++ library. A mix of Quick,Insertion and Heap) rather than alone. If the depth of Quick Sort becomes more than logn at any point
//algorithm switches to heap sort as heap sort has theta nlogn time complexity


#include <bits/stdc++.h>
using namespace std;


void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void heapify(int arr[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {swap(arr[i],arr[largest]);heapify(arr,n,largest);}
}

void buildHeap(int arr[],int n) //O(n) time complexity
{
    for(int i=(n-2)/2;i>=0;i--)
        heapify(arr,n,i);
}

void HeapSort(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0); //logn time complexity
    }

}
int main()
{
	int arr[10]={56,90,81,72,60,1,23,49,3,100};
	cout<<"Given Array is: ";
	print(arr,10);
	cout<<endl;
	buildHeap(arr,10);
	HeapSort(arr,10);
	cout<<"Sorted Array is: ";
	print(arr,10);

	return 0;
}
