#include <iostream>
using namespace std;

bool is_palindrome(string s,int start,int end)
{
   if(start>=end)
      return true;
   return ((s[start]==start[end])&&(is_palindrome(s,start+1,end-1));
}

int main()
{
   string s; cin>>s;
   int n=s.length();
   int start=0, end=n-1;
   if(is_palindrome(s,start,end))
      cout<<"true";
   else cout<<"false";
   return 0;
}
