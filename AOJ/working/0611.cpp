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

signed main() {
	int n, m; cin >> n >> m;
	vector<int>d(n), c(m);
	rep(i, 0, n)cin >> d[i]; rep(i, 0, m)cin >> c[i];
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, INF));
	rep(i, 0, m + 1)dp[i][0] = 0;
	rep(i, 1, m + 1) {
		rep(j, 1, n + 1) {
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + c[i - 1] * d[j - 1]);
		}
	}
	cout << dp[m][n] << endl;
	//rep(i, 0, m + 1) {
	//	rep(j, 0, n + 1) {
	//		if (dp[i][j] == INF)cout << "INF";
	//		else cout << dp[i][j];
	//		cout << (j + 1 < n + 1 ? ' ' : '\n');
	//	}
	//}

	return 0;
}