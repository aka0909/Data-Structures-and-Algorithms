#include <bits/stdc++.h>
using namespace std;

const int CHAR=256;

int LRE_Better(string &str) //Works only when length of string is constant; Two traversals
{
  int count[CHAR]={0};
  for(int i=0;i<str.length();i++)
  {
      count[str[i]]++;
  }
  for(int i=0;i<str.length();i++)
  {
      if(count[str[i]]>1)
        return i;
  }
  return -1;

}

int LRE_Efficient(string &str)   //Suited for the case when length of string is increasing during runtime & 1 traversal
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    int res=INT_MAX;
    for(int i=0;i<str.length();i++)
    {
        if(fI[str[i]]==-1)
            fI[str[i]]=i;
        else
            res=min(res,fI[str[i]]);

    }
    return (res==INT_MAX)?-1:res;

}

int LRE_MostEfficient(string &str) //One traversal. No need to use res=min(res,fI[str[i]])
{
    bool visited[CHAR];
    int res=-1;
    fill(visited,visited+CHAR,false);
    for(int i=str.length()-1;i>=0;i--)
    {
        if(visited[str[i]])
            res=i;
        else
            visited[str[i]]=true;
    }
    return res;

}

int main()
{
    string str = "geeksforgeeks";
    cout<<"Index of leftmost repeating character:"<<endl;
    cout<<LRE_MostEfficient(str)<<endl;
    cout<<LRE_Efficient(str)<<endl;
    cout<<LRE_Better(str)<<endl;
    return 0;
}
