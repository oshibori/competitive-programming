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
	int n;
	while (cin >> n, n) {
		vector<pair<int, int> >v(n);
		rep(i, 0, n)cin >> v[i].second >> v[i].first;
		sort(v.begin(), v.end());
		rep(i, 1, n) {
			v[i].second += v[i - 1].second;
		}
		bool f = true;
		rep(i, 0, n) {
			if (v[i].second > v[i].first) f = false;
		}
		if (f)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}