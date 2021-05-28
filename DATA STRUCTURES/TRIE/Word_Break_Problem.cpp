#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

struct TrieNode{
TrieNode* child[26];
bool isend;
};

struct TrieNode *newtrienode(void)
{
    struct TrieNode *newNode = new TrieNode;
    newNode->isend = false;
    for (int i = 0; i<26; i++)
        newNode->child[i] = NULL;
    return newNode;
}
void insert(struct TrieNode *root,string s)
{
    struct TrieNode *curr=root;
    for(int i=0;i<s.length();i++)
    {
        int idx=s[i]-'a';
        if(curr->child[idx]==NULL)
        {
            curr->child[idx]=newtrienode();
        }

        curr=curr->child[idx];
    }
    curr->isend=true;
}
bool Search (struct TrieNode *root, string key)
{
    struct TrieNode *curr=root;
    for(int i=0;i<key.length();i++)
    {
        int idx=key[i]-'a';
        if(curr->child[idx]==NULL)
            return false;
        curr=curr->child[idx];
    }
    return (curr!=NULL && curr->isend);
}

bool WordBreak(string str, struct TrieNode *root)
{
    int n=str.length();
    if(n==0)return true;

    for(int i=1;i<=n;i++)
    {
        if(Search(root,str.substr(0,i))&& WordBreak(str.substr(i,n-i),root))
            return true;

    }
    return false;

}


int main()
{
    string dictionary[] = {"mobile","samsung","sam",
                           "sung","ma\n","mango",
                           "icecream","and","go","i",
                           "like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    struct TrieNode *root = newtrienode();


    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);

    WordBreak("ilikesamsung", root)? cout <<"Yes\n": cout << "No\n";
    WordBreak("iiiiiiii", root)? cout <<"Yes\n": cout << "No\n";
    WordBreak("", root)? cout <<"Yes\n": cout << "No\n";
    WordBreak("ilikelikeimangoiii", root)? cout <<"Yes\n": cout << "No\n";
    WordBreak("samsungandmango", root)? cout <<"Yes\n": cout << "No\n";
    WordBreak("samsungandmangok", root)? cout <<"Yes\n": cout << "No\n";
    return 0;
}
