#include <bits/stdc++.h>
using namespace std;

void ReverseWords(char str[],int n) //Auxiliary Space: O(1). Alernate solution with stack but has Auxiliary Space=Theta N
{
    int start=0;
    for(int end=start;end<n;end++)
    {
        if(str[end]==" ")
        {
            reverse(str+start,str+(end-1));
            start=end+1;
        }
    }
    reverse(str+start;str+(n-1));
    reverse(str,str+n-1);
}
int main()
{
    string s ="Welcome to Gfg"; //char str[]="Welcome to Gfg";
    int n=s.length();//n=sizeof(str)/sizeof(str[0])-1;(Because there will be a backslash zero at the end
    char str[n];//No need for this
    strcpy(str, s.c_str());//No need for this
    cout<<"After reversing the words:"<<endl;
    ReverseWords(str,n);
    for(int i=;i<n;i++)
    {
        cout<<str[i];
    }
    return 0;    
}
