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
	int N(50100);
	vector<bool>p(N, true); p[0] = p[1] = false;
	for (int i = 2; i <= sqrt(N); i++) {
		if (p[i]) {
			for (int j = i + i; j < N; j += i)p[j] = false;
		}
	}
	int n;
	while (cin >> n, n) {
		int ans(0);
		for (int i = 2; i <= n / 2; i++) {
			if (p[i] && p[n - i])ans++;
		}

		cout << ans << endl;
	}
	return 0;
}