#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

void dfs(vector<set<int>>&g, vector<int>&f, int p) {
	if (f[p])return;
	f[p] = 1;
	for (auto &o : g[p]) {
		dfs(g, f, o);
	}

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<int> a(M), b(M); rep(i, 0, M) { cin >> a[i] >> b[i]; a[i]--, b[i]--; }
	vector<set<int>>G(N);
	rep(i, 0, M) {
		G[a[i]].insert(b[i]);
		G[b[i]].insert(a[i]);
	}
	int ans(0);
	rep(i, 0, M) {
		G[a[i]].erase(b[i]);
		G[b[i]].erase(a[i]);
		vector<int>f(N, 0);
		dfs(G, f, 0);
		dump(f);
		ans += (accumulate(all(f), 0) != N);
		G[a[i]].insert(b[i]);
		G[b[i]].insert(a[i]);

	}
	cout << ans << endl;
	return 0;
}