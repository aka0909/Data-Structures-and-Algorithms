#include <bits/stdc++.h>
using namespace std;

const int R=4,C=4;

void Boundary_Traversal(int arr[R][C])
{
   for(int j=0;j<C;j++)
     cout<<arr[0][j]<<" ";
   for(int i=1;i<R;i++)
     cout<<arr[i][C-1]<<" ";
   for(int j=C-2;j>=0;j--)
     cout<<arr[R-1][j]<<" ";
   for(int i=R-2;i>=1;i--)
     cout<<arr[i][0]<<" ";

   cout<<endl;

}
int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {9, 10, 11, 12},
				   {13, 14, 15, 16}};

    Boundary_Traversal(arr);

    return 0;
}
