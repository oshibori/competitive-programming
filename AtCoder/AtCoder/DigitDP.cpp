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
	string A; cin >> A; int n(A.length());
	static int dp[101][2][2][3];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;// pos, less, has3, mod3

	rep(i, 0, n)rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 3) {
		int D(A[i] - '0');
		for (int d = 0; d <= (j ? 9 : D); d++)
			dp[i + 1][j || d < D][k || d == 3][(l + d) % 3] += dp[i][j][k][l];
	}

	return 0;
}