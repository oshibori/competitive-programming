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
	int N; cin >> N;
	vector<vector<int>>dp(3, vector<int>(N + 1, 0));
	dp[0][0] = 1; dp[0][1] = 1;
	dp[1][2] = 1;
	rep(i, 3, N + 1) {
		dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 2] + dp[2][i - 2]) % MOD;
		dp[2][i] = (dp[0][i - 3] + dp[1][i - 3]) % MOD;
	}
	cout << (((dp[0][N] + dp[1][N]) % MOD) + dp[2][N]) % MOD << endl;
	return 0;
}