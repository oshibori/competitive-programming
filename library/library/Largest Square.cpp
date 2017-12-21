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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W; cin >> H >> W;
	vector<vector<int>>G(H, vector<int>(W));
	vector<vector<int>>dp(G);
	int ans(0);
	rep(i, 0, H)rep(j, 0, W)cin >> G[i][j];
	rep(i, 0, H)rep(j, 0, W) {
		dp[i][j] = (G[i][j] + 1) % 2;
		chmax(ans, dp[i][j]);
	}
	
	rep(i, 1, H)rep(j, 1, W) {
		if (G[i][j])dp[i][j] = 0;
		else dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
		chmax(ans, dp[i][j]);
	}
	cout << ans*ans << endl;
	return 0;
}