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
	int H, W; cin >> H >> W;
	vector<vector<int>>a(H, vector<int>(W));
	rep(i, 0, H)rep(j, 0, W)cin >> a[i][j];
	auto within = [&](int x, int y) {return 0 <= x&&x < H && 0 <= y&&y < W; };
	int dx[]{ 1,0,-1,0 }, dy[]{ 0,1,0,-1 };
	vector<vector<int>>dp(H, vector<int>(W, 0));

	function<int(int, int)> dfs = [&](int x, int y) {

		if (dp[x][y] != 0)return dp[x][y];
		int ret(1);
		rep(k, 0, 4) {
			int X = x + dx[k], Y = y + dy[k];
			if (within(X, Y) && a[x][y] < a[X][Y])ret += dfs(X, Y) % MOD;
		}

		return dp[x][y] = ret%MOD;
	};

	int ans(0);

	rep(i, 0, H)rep(j, 0, W)ans = (ans + dfs(i, j)) % MOD;

	cout << ans << endl;

	return 0;
}