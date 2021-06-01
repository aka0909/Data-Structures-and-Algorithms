#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

struct Interval
{
    int start, end;
};

static bool mycmp(struct Interval a,struct Interval b)
{
    return a.start<b.start;
}

void mergeinterval(struct Interval arr[],int n)
{
    stack<Interval>st;
    sort(arr,arr+n,mycmp);
    st.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        Interval x=st.top();
        if(x.end<arr[i].start)
            st.push(arr[i]);
        else if(x.end>=arr[i].start)
        {
            st.pop();
            x.end=max(x.end,arr[i].end);
            st.push(x);
        }
    }
    cout << "\n The Merged Intervals are: ";
    while (!st.empty())
    {
        Interval t = st.top();
        cout << "[" << t.start << "," << t.end << "] ";
        st.pop();
    }
    return;
}



int main()
{
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeinterval(arr, n);
    return 0;

}
