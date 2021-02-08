#include <bits/stdc++.h>
using namespace std;

const int R=4,C=4;

void Transpose(int arr[R][C])
{
   for(int j=0;j<C;j++)
   {
       for(int i=0;i<R;i++)
        cout<<arr[i][j]<<" ";
       cout<<endl;
   }

}
int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {9, 10, 11, 12},
				   {13, 14, 15, 16}};

    Transpose(arr);

    return 0;
}
