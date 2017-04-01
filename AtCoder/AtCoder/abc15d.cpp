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
	int W; cin >> W;
	int N, K; cin >> N >> K;
	vector<int>A(N + 1), B(N + 1);
	rep(i, 1, N + 1)cin >> A[i] >> B[i];
	static int dp[51][51][10010]; memset(dp, 0, sizeof(dp));
	rep(i, 1, N + 1)rep(j, 1, i + 1)rep(k, 0, W + 1) {
		dp[i][j][k] = dp[i - 1][j][k];
		if(k-A[i]>=0)
			dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - 1][k - A[i]] + B[i]);
	}
	int ans(0);
	rep(i, 0, K+1)chmax(ans, dp[N][i][W]);
	cout << ans << endl;

	return 0;
}