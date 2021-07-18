#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int enterTime[100005];
int exitTime[100005];
bool visited[100005];

int timer = 0;

void dfs(int i) {
    visited[i] = true;
    enterTime[i] = timer;
    timer++;
    for(int next : adj[i]) {
        if(!visited[next]) dfs(next);
    }
    exitTime[i] = timer++;
}

bool solve(int x, int y) {
    return (enterTime[x] < enterTime[y] && exitTime[x] > exitTime[y]);
}

int main() {
	int n;
	scanf("%d\n", &n);
	for(int i=0; i<n-1; i++) {
		int a, b;
		scanf("%d%d\n", &a, &b);
		adj[a].push_back(b);
	}
    dfs(1);
    int q;
    scanf("%d\n",&q );
    while(q--) {
        bool flag;
        int type, x, y;
        scanf("%d%d%d",&type, &x, &y);
        if(type == 0) flag = solve(x, y);
        else flag = solve(y, x);
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
