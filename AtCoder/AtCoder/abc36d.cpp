#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
vector<int>b, w;
vector<vector<int>>G;
int N;
int black(int, int);
int white(int, int);
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	G = vector<vector<int>>(N);
	b = vector<int>(N, -1);
	w = vector<int>(N, -1);
	rep(i, 0, N-1) {
		dump(i);
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout << (black(0, -1) + white(0, -1)) % MOD << endl;
	return 0;
}
int black(int cur, int prev) {
	if (b[cur] != -1)return b[cur];
	int ret(1);
	rep(i, 0, G[cur].size()) {
		if (G[cur][i] == prev)continue;
		(ret *= white(G[cur][i], cur) )%= MOD;
	}
	return b[cur] = ret;
}
int white(int cur, int prev) {
	if (w[cur] != -1)return w[cur];
	int ret(1);
	rep(i, 0, G[cur].size()) {
		if (G[cur][i] == prev)continue;
		(ret *= white(G[cur][i], cur) + black(G[cur][i], cur)) %= MOD;
	}
	return w[cur] = ret;
}