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
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
signed main() {
	int n, Ma, Mb; cin >> n >> Ma >> Mb;
	vector<int>a(n), b(n), c(n);
	rep(i, 0, n) {
		cin >> a[i] >> b[i] >> c[i];

	}
	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(409, vector<int>(409, INF)));
	dp[0][0][0] = 0;
	rep(i, 0, n) {
		rep(j, 0, 409) {
			rep(k, 0, 409) {
				if (dp[i][j][k] != INF) {
					dp[i + 1][j][k] = min(dp[i][j][k], dp[i + 1][j][k]);

					dp[i + 1][j+a[i]][k+b[i]] = min(dp[i + 1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
				}
			}
		}
	}
	int ans = INF;
	rep(i, 1, 409) {
		rep(j, 1, 409) {
			if (i*Mb == j*Ma)ans = min(ans, dp[n][i][j]);
		}
	}
	cout << ((ans == INF) ? -1 : ans) << endl;
	return 0;
}