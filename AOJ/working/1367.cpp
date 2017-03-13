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
	int n, m; cin >> n >> m;
	vector<bool>v(n + 1, false);
	vector<int>ans, given;
	rep(i, 0, m) {
		int a; cin >> a; given.push_back(a);
	}
	rrep(i, 0, m) {
		if (v[given[i]] == false) {
			ans.push_back(given[i]);
			v[given[i]] = true;
		}
	}
	rep(i, 1, n + 1) {
		if (v[i] == false) {
			ans.push_back(i);
			v[i] = true;
		}
	}

	rep(i, 0, n)cout << ans[i] << endl;
	return 0;
}