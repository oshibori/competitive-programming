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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int inf(123456789);
	int N, M; cin >> N >> M;
	vector<vector<int>>G(N, vector<int>(N, inf));
	rep(i, 0, N)G[i][i] = 0;
	rep(i, 0, M) {
		int u, v, l; cin >> u >> v >> l; u--, v--;
		G[u][v] = G[v][u] = l;
	}
	rep(k, 1, N)rep(i, 1, N)rep(j, 1, N) {
		G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	}

	int ans(inf);

	rep(i, 1, N)rep(j, i + 1, N) {
		ans = min(ans, G[0][i] + G[i][j] + G[j][0]);
	}



	cout << (ans == (inf) ? -1 : ans) << endl;
	return 0;
}