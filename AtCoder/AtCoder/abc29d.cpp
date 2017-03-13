#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;

signed main() {
	string s; cin >> s;
	int n(s.size());
	int dp[15][2][10];// pos, less, num of 1
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	rep(i, 0, n)rep(j, 0, 2)rep(k, 0, 10) {
		int D(s[i] - '0');
		for (int d = 0; d <= (j ? 9 : D); d++)
			dp[i + 1][j || d < D][k + (d == 1)] += dp[i][j][k];
	}
	int ans(0);
	rep(j, 0, 2) rep(k, 1, 10) {
		ans += dp[n][j][k] * k;
	}
	cout << ans << endl;
	return 0;
}