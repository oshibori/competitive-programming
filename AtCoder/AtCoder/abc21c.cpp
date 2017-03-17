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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, a, b, M; cin >> N >> a >> b >> M; a--, b--;
	vector<vector<int>>G(N, vector<int>(N, 0));
	rep(i, 0, M) {
		int x, y; cin >> x >> y; x--, y--;
		G[x][y] = G[y][x] = 1;
	}

	vector<vector<int>>dp(N, vector<int>(N, 0)); // dp[c][j]@‚ƒ‰ñ‚Åj‚É’…‚­Œo˜H”
	dp[0][a] = 1;
	rep(c, 1, N)rep(j, 0, N)rep(i, 0, N) {
		if (G[i][j])dp[c][j] = (dp[c - 1][i] + dp[c][j]) % MOD;
	}
	int ans(INF);
	rep(i, 0, N)if (dp[i][b] > 0) {
		cout << dp[i][b] << endl;
		break;
	}
	return 0;
}