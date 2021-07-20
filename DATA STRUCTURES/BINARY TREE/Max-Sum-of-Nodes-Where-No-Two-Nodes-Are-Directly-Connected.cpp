// C++ program to find maximum sum from a subset of
// nodes of binary tree such that no two nodes are adjacent i.e directly connected
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node
{
	int data;
	struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int getGrandChildrenSum(node* root,unordered_map<node*,int> &mp);
int getMaxSum(node* root);
int getMaxSumUtil(node* root, unordered_map<node*,int> &mp);


int getGrandChildrenSum(node* root,unordered_map<node*,int> &mp)
{
    int sum=0;

    if(root->left)
    {
        sum+=getMaxSumUtil(root->left->left,mp)+getMaxSumUtil(root->left->right,mp);
    }
    if(root->right)
    {
        sum+=getMaxSumUtil(root->right->left,mp)+getMaxSumUtil(root->right->right,mp);
    }
    return sum;
}

int getMaxSumUtil(node* root, unordered_map<node*,int> &mp)
{
    if(root==NULL)return 0;

    if(mp.find(root)!=mp.end())
        return mp[root];

    int incl=root->data+getGrandChildrenSum(root,mp);

    int excl=getMaxSumUtil(root->left,mp)+getMaxSumUtil(root->right,mp);

    mp[root]=max(excl,incl);

    return mp[root];
}



int getMaxSum(node* root)
{

    if(root==NULL)return 0;
    unordered_map<node*,int> mp;
    return getMaxSumUtil(root,mp);
}

// Driver code to test above methods
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left = newNode(1);

	cout << getMaxSum(root) << endl;
	return 0;
}
