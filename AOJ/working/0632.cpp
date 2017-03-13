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
	int n, m, d; cin >> n >> m >> d;
	vector<string>v(n);
	rep(i, 0, n)cin >> v[i];
	int ans(0);
	rep(i, 0, n) {
		for (int j = 0; j + d <= m; j++) {
			if (count(v[i].begin() + j, v[i].begin() + j + d, '.') == d)ans++;
		}
	}
	vector<string>w;
	rrep(i, 0, m) {
		string s;
		rep(j, 0, n)s.push_back(v[j][i]);
		w.push_back(s);
	}

	rep(i, 0, m) {
		for (int j = 0; j + d <= n; j++) {
			if (count(w[i].begin() + j, w[i].begin() + j + d, '.') == d)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}