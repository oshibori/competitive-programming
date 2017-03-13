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
void pv(vector<int>v) {
	rep(i, 0, v.size())cout << v[i] << " ";
	cout << endl;
}
signed main() {
	int n; cin >> n; vector<int>v(n); rep(i, 0, n)cin >> v[i];
	vector<int>dp(n);
	dp[0] = 0;
	dp[1] = abs(v[1] - v[0]);
	pv(dp);
	rep(i, 2, n) {
		dp[i] = min(dp[i - 2] + abs(v[i] - v[i - 2]), dp[i - 1] + abs(v[i] - v[i - 1]));
		pv(dp);
	}
	cout << dp[n - 1] << endl;
	return 0;
}