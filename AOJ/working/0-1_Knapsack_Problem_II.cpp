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
	int N, W; cin >> N >> W;
	vector<int>v(N + 1), w(N + 1);
	rep(i, 1, N + 1)cin >> v[i] >> w[i];
	vector<int>dp(100 * 100 + 1, INF);
	dp[0] = 0;
	rep(i, 1, N + 1)rrep(j, v[i], dp.size()) {
		dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
	}
	int ans(0);
	rep(i, 0, dp.size()) {
		if (dp[i] <= W)ans = max(ans, i);
	}
	cout << ans << endl;
	return 0;
}