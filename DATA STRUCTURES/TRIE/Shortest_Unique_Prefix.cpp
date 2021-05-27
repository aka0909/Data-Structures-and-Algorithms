#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

struct TrieNode{
TrieNode* child[256];
int freq;
};

struct TrieNode *newtrienode(void)
{
    struct TrieNode *newNode = new TrieNode;
    newNode->freq = 1;
    for (int i = 0; i<256; i++)
        newNode->child[i] = NULL;
    return newNode;
}
void insert(struct TrieNode *root,string s)
{
    struct TrieNode *curr=root;
    for(int i=0;i<s.length();i++)
    {
        int idx=s[i];
        if(curr->child[idx]==NULL)
        {
            curr->child[idx]=newtrienode();
        }
        else
            curr->child[idx]->freq++;

        curr=curr->child[idx];
    }
}

void findPrefixesUtil(struct TrieNode *root, char prefix[],
                      int ind)
{
    // Corner case
    if (root == NULL)
       return;

    // Base case
    if (root->freq == 1)
    {
       prefix[ind] = '\0';
       cout << prefix << " ";
       return;
    }

    for (int i=0; i<256; i++)
    {
       if (root->child[i] != NULL)
       {
           prefix[ind] = i;
           findPrefixesUtil(root->child[i], prefix, ind+1);
       }
    }
}
void findPrefixes(string arr[], int n)
{
    struct TrieNode *root = newtrienode();
    root->freq = 0;
    for (int i = 0; i<n; i++)
        insert(root, arr[i]);

    // Create an array to store all prefixes
    char prefix[MAX_WORD_LEN];

    findPrefixesUtil(root, prefix, 0);
}

int main()
{
    string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr)/sizeof(arr[0]);
    findPrefixes(arr, n);

    return 0;
}
