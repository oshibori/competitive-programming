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
	int n, m; cin >> n >> m; vector<int>v(2 * n);
	rep(i, 0, v.size())v[i] = i + 1;
	int k;
	while (m--) {
		cin >> k;
		if (k == 0) {
			vector<int>w(v);
			int a(0);
			rep(i, 0, n) {
				w[a++] = v[i];
				w[a++] = v[i + n];
			}
			v = w;
		}
		else {
			vector<int>w(v);
			int a(0);
			rep(i, k, v.size())w[a++] = v[i];
			rep(i, 0, k)w[a++] = v[i];
			v = w;
		}
	}
	rep(i, 0, v.size())cout << v[i] << endl;
	return 0;
}