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
int Largest_Square(const vector<vector<int>> &field) {
	int H = field.size(), W = field[0].size();
	vector<vector<int>>dp(H, vector<int>(W)); // dp[i][j]=タイル(i,j)から左上に向かってできる最大の正方形の辺の長さ
	rep(i, 0, H)rep(j, 0, W) dp[i][j] = (field[i][j] + 1) % 2; // 使えないマスは０、使えるマスは１
	int ret(0);
	rep(i, 0, H)chmax(ret, dp[i][0]); rep(i, 0, W)chmax(ret, dp[0][i]);
	rep(i, 1, H)rep(j, 1, W)
		if (dp[i][j])chmax(ret, dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])));
	if (_DEBUG) {
		cout << endl;
		rep(i, 0, H)rep(j, 0, W)cout << dp[i][j] << (j == W - 1 ? '\n' : ' ');
	}
	return ret*ret;// 返り値は面積の最大値
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	vector<vector<int>>G(H, vector<int>(W));
	rep(i, 0, H)rep(j, 0, W)cin >> G[i][j];
	cout << Largest_Square(G) << endl;
	return 0;
}