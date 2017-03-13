#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int W = 0, B = 1;
int n,tt; vector<vector<int>>M; vector<int>color, d, f, nt;
int next(int u) {
	rep(i, nt[u], n) {
		nt[u] = i + 1;
		if (M[u][i])return i;
	}
	return -1;
}
void dfs_visit(int r) {
	nt = vector<int>(n, 0);
	stack<int>S;
	S.push(r);
	color[r] = B;
	d[r] = ++tt;
	while (!S.empty()) {
		int u = S.top();
		int v = next(u);
		if (v != -1) {
			if (color[v] == W) {
				color[v] = B;
				d[v] = ++tt;
				S.push(v);
			}
		}
		else {
			S.pop();
			f[u] = ++tt;
		}
	}
}
void dfs() {
	color = vector<int>(n, W);
	tt = 0;
	rep(u, 0, n) {
		if (color[u] == W)dfs_visit(u);
	}
	rep(i, 0, n) {
		cout << i + 1 << " " << d[i] << " " << f[i] << endl;
	}
}
signed main() {
	int u, k, v;
	cin >> n;
	M = vector<vector<int>>(n, vector<int>(n, 0));
	rep(i, 0, n) {
		cin >> u >> k; u--;
		rep(j, 0, k) {
			cin >> v; v--;
			M[u][v] = 1;
		}
	}
	dfs();
	return 0;
}