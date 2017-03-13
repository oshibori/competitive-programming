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

void dfs(int u) {
	V[u] = true;
	rep(i, 0, G[u].size()) {
		int v = G[u][i];
		if (!V[v])dfs(v);
	}
	out.push_back(u);
}

signed main() {
	int s, t, M;
	cin >> N >> M;
	V = vector<bool>(N, false); G = vector<vector<int>>(N, vector<int>());
	rep(i, 0, M) {
		cin >> s >> t;
		G[s].push_back(t);
	}
	rep(i, 0, N) {
		if (!V[i])dfs(i);
	}
	reverse(out.begin(), out.end());
	each(it, out)cout << *it << endl;
	return 0;
}