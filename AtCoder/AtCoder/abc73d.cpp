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
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, R; cin >> N >> M >> R;
	vector<int> r(R); rep(i, 0, R) { cin >> r[i]; r[i]--; }
	vector<vector<int>>g(N, vector<int>(N, INF));
	rep(i, 0, N)g[i][i] = 0;
	rep(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		g[a][b] = c;
		g[b][a] = c;

	}
	rep(k, 0, N) {
		rep(i, 0, N) {
			if (g[i][k] == INF)continue;
			rep(j, 0, N) {
				if (g[k][j] == INF)continue;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	int ans(INF);
	vector<int>p(min(8ll, R));
	rep(i, 0, p.size()) {
		p[i] = i;
	}
	dump(g, p);
	do {
		int cur = r[p[0]];
		int tmp(0);
		rep(i, 1, p.size()) {
			tmp += g[cur][r[p[i]]];
			cur = r[p[i]];
		}
		chmin(ans, tmp);
	} while (next_permutation(all(p)));

	cout << ans << endl;
	return 0;
}