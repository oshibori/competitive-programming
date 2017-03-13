#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
int pow2(int x, int y) {
	if (y <= 0)return 1;
	int res = pow2(x*x, y / 2);
	if (y & 1)res *= x;
	return res;
}
signed main() {
	int n; cin >> n;
	vector<bool>prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (prime[i]) {
			for (int j = 2; i*j <= n; j++) {
				prime[i*j] = false;
			}
		}
	}
	vector<int>v(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		if (prime[i]) {
			for (int j = 1; n / pow2(i, j); j++) {
				v[i] += n / pow2(i, j);
			}
		}
	}
	int ans = 1;
	for (int i = 0; i <= n; i++) {
		ans = (ans*(v[i] + 1)) % MOD;
	}
	cout << ans << endl;
	return 0;
}