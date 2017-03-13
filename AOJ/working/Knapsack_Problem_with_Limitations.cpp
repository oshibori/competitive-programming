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
	vector<int>v, w; v.push_back(0), w.push_back(0);
	rep(i, 0, N) {
		int a, b, m; cin >> a >> b >> m;

		for (int x = 1; x <= m; x++) {
			v.push_back(x*a);
			w.push_back(x*b);
			m -= x;
		}
		if (m > 0) v.push_back(m*a), w.push_back(m*b);

	}
	vector<int>dp(W + 1, 0);
	rep(i, 1, v.size())rrep(j, w[i], W + 1) {
		dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	}
	cout << dp[W] << endl;

	return 0;
}