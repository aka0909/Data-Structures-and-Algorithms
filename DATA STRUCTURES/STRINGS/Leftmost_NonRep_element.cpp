#include <bits/stdc++.h>
using namespace std;

const int CHAR=256;

int LNRE_Efficient(string &str)   //Suited for the case when length of string is increasing during runtime
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    for(int i=0;i<str.length();i++)
    {
        if(fI[str[i]]==-1)
            fI[str[i]]=i;
        else
            fI[str[i]]=-2;

    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++)
    {
        if(fI[i]>0)
            res=min(res,fI[i]);
    }
    if(res==INT_MAX)
        return -1;
    return res;

}

int LNRE_Better(string &str) //Works only when length of string is constant
{
  int count[CHAR]={0};
  for(int i=0;i<str.length();i++)
  {
      count[str[i]]++;
  }
  for(int i=0;i<str.length();i++)
  {
      if(count[str[i]]==1)
        return i;
  }
  return -1;

}
int main()
{
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<LNRE_Better(str)<<endl;
    cout<<LNRE_Efficient(str)<<endl;
    return 0;

}
