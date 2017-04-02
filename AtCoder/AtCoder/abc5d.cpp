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
	int N; cin >> N; vector<vector<int>>dp(N + 1, vector<int>(N + 1));// 1 origin
	rep(i, 1, N + 1)rep(j, 1, N + 1)cin >> dp[i][j];
	rep(i, 2, N + 1)dp[1][i] += dp[1][i - 1], dp[i][1] += dp[i - 1][1];
	rep(i, 2, N + 1)rep(j, 2, N + 1)dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

	vector<int>dpdp(N*N + 1, 0);

	rep(i, 1, N + 1)rep(j, 1, N + 1)rep(x, i, N + 1)rep(y, j, N + 1) {
		int takoyaki = x*y - (i - 1)*y - x*(j - 1) + (i - 1)*(j - 1);

		chmax(dpdp[takoyaki], dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1]);
	}

	rep(i, 1, N*N + 1)chmax(dpdp[i], dpdp[i - 1]);

	int Q; cin >> Q;
	rep(q, 0, Q) {
		int p; cin >> p;
		cout << dpdp[p] << endl;
	}


	return 0;
}