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
	while (1) {
		int a, b,c(-1);
		vector<int>v(101, 0); int m = 0;
		while (cin >> a >> b, a || b) {
			v[a]++; v[b]++;
			m = max(m, a);
			m = max(m, b);
			c = 1;
		}
		if (c == -1)return 0;
		bool f(true);
		rep(i, 3, m + 1) {
			if (v[i] & 1)f = false;
		}
		if (v[1] & 1 && v[2] & 1 && f)cout << "OK" << endl;
		else cout << "NG" << endl;
	}
	return 0;
}