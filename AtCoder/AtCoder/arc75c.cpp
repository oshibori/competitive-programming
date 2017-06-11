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
	vector<int> s(N); rep(i, 0, N) { cin >> s[i]; }
	vector<int>dp(100 * 100 + 1, 0);
	dp[0] = 1;
	int ans(0);
	rep(i, 0, N)rrep(j, s[i], dp.size())
		chmax(dp[j], dp[j - s[i]]);
	rrep(i, 0, dp.size()) {
		if (dp[i] == 1 && i % 10 != 0) {
			chmax(ans, i);
		}
	}
	cout << ans << endl;
	return 0;
}