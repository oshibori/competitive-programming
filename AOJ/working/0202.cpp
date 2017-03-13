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
const int X = 1001000;
signed main() {
	vector<bool>prime(X, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(X); i++) {
		if (prime[i]) {
			for (int j = i * 2; j < X; j += i) {
				prime[j] = false;
			}
		}
	}
	int n, x;
	while (cin >> n >> x,n||x) {
		vector<bool>money(x+100, false); money[0] = true;
		vector<int>v(n); rep(i, 0, n)cin >> v[i];
		rep(i, 0, n) {
			rep(j, 0, x+100 - v[i]) {
				if (money[j]) {
					money[j + v[i]] = true;
				}
			}
		}
		int ans(-1);
		for (int i = x ; i >= 1; i--) {
			if (prime[i] && money[i]) {
				ans = i;
				break;
			}
		}
		if (ans == -1)cout << "NA" << endl;
		else cout << ans << endl;

	}
	return 0;
}