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

	int N, M; cin >> N >> M;
	vector<int>dp(N + 1, 0), v(N + 1);
	rep(i, 0, N)cin >> v[i];
	vector<int>used(M + 1, 0);
	dp[0] = 1;
	int l(0), sum(0), i(0);
	while (i < N) {
		while (l < N && used[v[i]]) {
			used[v[l]] = 0;
			sum = (sum - dp[l] + MOD) % MOD;
			l++;
			dump(l, sum);
		}

		used[v[i]] = 1;
		sum += dp[i] %= MOD;
		dp[++i] = sum%MOD;

		dump(dp);

	}
	cout << dp[N] << endl;
	return 0;
}