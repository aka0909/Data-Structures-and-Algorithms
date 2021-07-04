#include <bits/stdc++.h>
using namespace std;

int kthLargestSum(int a[],int n,int k)
{
    int sum[n+1];
    sum[0]=0;
    sum[1]=a[0];
    for(int i=2;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i-1];
    }

    priority_queue<int,vector<int>,greater<int>> q;

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int x=sum[j]-sum[i-1];

            if(q.size()<k)
                q.push(x);
            else
            {
                if(q.top()<x)
                {
                    q.pop();
                    q.push(x);
                }
            }
        }
    }
    return q.top();
}



// Driver code
int main()
{
    int a[] = { 10, -10, 20, -40 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;

    // calls the function to find out the
    // k-th largest sum
    cout << kthLargestSum(a, n, k);
    return 0;
}
