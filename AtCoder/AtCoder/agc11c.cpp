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
const double EPS = 1e-10;
vector<vector<int>>G;
int N, M;
vector<int>color;


void bsf(int s, int c) {
	queue<int>q;
	q.push(s);
	color[s] = c;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		rep(v, 0, G[u].size()) {
			if (color[G[u][v]] != -1)continue;
			color[G[u][v]] = c;
			q.push(G[u][v]);
		}
	}
}
int assignColor() {
	int c(1);
	rep(i, 0, N) {
		if (color[i] == -1)bsf(i, c++);
	}
	return c;
}
signed main() {
	cin >> N >> M; G = vector<vector<int>>(N);
	color = vector<int>(N, -1);
	rep(i, 0, M) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int c = assignColor();
	dumpc(color);

	return 0;
}