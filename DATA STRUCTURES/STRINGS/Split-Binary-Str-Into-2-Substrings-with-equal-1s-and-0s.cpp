#include<bits/stdc++.h>
using namespace std;

int countsplits(string s)
{
    int count0=0,count1=0;
    int n=s.length();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
            count0++;
        else if(s[i]=='1')
            count1++;
        if(count1==count0)
            cnt++;
    }
    if(count1!=count0)
        return -1;
    return cnt;

}

int main() {
    string s="0100110101";
    cout<<countsplits(s)<<endl;
	return 0;
}
