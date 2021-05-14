#include <bits/stdc++.h>
#include<string>
#include <math.h>
using namespace std;

#define pb push_back
#define qtime long long q;\
                        cin >> q;\
                        while(q--)
#define nl "\n"
#define fi first
#define int long long
#define se second
#define loop(i,n) for(long long i=0;i<n;i++)
#define rloop(i,n) for(long long i=n-1; i>=0; i--)
#define print(x) for(auto t : x)\
                            cout << t << " ";\
                            cout << "\n";
#define printnl(x) for(auto t : x)\
                               cout << t << endl;
#define all(x) x.begin(), x.end()
#define o(x) cout << x << "\n"
#define i(x) cin >> x;
#define itr(x,a,b) x.begin()+a, x.begin()+b;
#define fast ios_base::sync_with_stdio(false);\
                     cin.tie(NULL);
#define inp(x) long long x;\
                        cin >> x
#define loop1(i,a,b) for(long long i=a ; i<=b ; i++)
#define itrloop(it,x) for(auto it=x.begin(); it!=x.end(); it++)
#define NUM 1000000007
#define PI 3.1415926536
#define fileIO freopen("input.txt", "r", stdin);\
                       freopen("output.txt", "w", stdout);
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<long long> vl;
typedef vector<int> vi;
typedef vector <string> vs;
typedef vector <char> vc;
typedef set<long long> sl;
typedef set<int> si;
typedef set <string> ss;
typedef set <char> sc;
typedef set <double> sd;
typedef map<long long, long long> ml;
typedef map<int,int> mi;
typedef map <string, int> ms;
typedef map <char,int> mc;


void solve()
{
   ll n,sum;cin>>n>>sum;
   ll arr[n];
   loop(i,n)cin>>arr[i];
   ll dp[sum+1];
   dp[0]=0;
   for(ll i=1;i<=sum;i++)
   {
       dp[i]=INT_MAX;
       loop(j,n)
       {
           if(i-arr[j]>=0)
           {
             dp[i]=min(dp[i],dp[i-arr[j]]);
           }
           else
            continue;
       }
       if(dp[i]!=INT_MAX)
        dp[i]++;
   }
   cout<<dp[sum]<<endl;
}



signed main()
{
//    fileIO;
    fast;
    //SieveOfEratosthenes(1e+7);
    ll q = 1;
    //cin >> q;
    //ll i=1;
    while(q--)
      {
        solve();
      }
      return 0;

}
