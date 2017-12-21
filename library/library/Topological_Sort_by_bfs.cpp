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
vector<vector<int>>G;
list<int>out;
vector<bool>V;
int N;
vector<int>indeg;

void bfs(int s) {
	queue<int>q;
	q.push(s);
	V[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		out.push_back(u);
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			indeg[v]--;
			if (indeg[v] == 0 && !V[v]) {
				V[v] = true;
				q.push(v);
			}
		}
	}
}

void tsort() {
	indeg = vector<int>(N, 0);
	rep(u, 0, N) {
		rep(i, 0, G[u].size()) {
			int v = G[u][i];
			indeg[v]++;
		}
	}
	rep(u, 0, N) {
		if (indeg[u] == 0 && !V[u])bfs(u);
	}
	each(it,out)cout << *it << endl;
}
signed main() {
	int s, t, M;
	cin >> N >> M;
	V = vector<bool>(N, false); G = vector<vector<int>>(N, vector<int>());
	rep(i, 0, M) {
		cin >> s >> t;
		G[s].push_back(t);
	}
	tsort();
	return 0;
}