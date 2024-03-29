// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include<bits/stdc++.h>
using namespace std;

// Inorder Traversal of Binary Tree
void inorder(int a[], std::vector<int> &v,int n, int index)
{
    if(index>=n)return;

    inorder(a,v,n,2*index+1);

    v.push_back(a[index]);

    inorder(a,v,n,2*index+2);
}

// Function to find minimum swaps to sort an array
int minSwaps(std::vector<int> &v)
{
    vector<pair<int,int>> temp(v.size());

    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        temp[i].first=v[i];
        temp[i].second=i;
    }
    sort(temp.begin(),temp.end());

    for(int i=0;i<v.size();i++){
        if(temp[i].second==i)
            continue;
        else
        {
            swap(temp[i].first,temp[temp[i].second].first);
            swap(temp[i].second,temp[temp[i].second].second);
        }
        if(i!=temp[i].second)
        --i;

        ans++;
    }
    return ans;

}

// Driver code
int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	std::vector<int> v;
	inorder(a, v, n, 0);
	cout << minSwaps(v) << endl;
}


