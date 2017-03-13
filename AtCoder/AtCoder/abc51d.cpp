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
	int n, m; cin >> n >> m; vector<vector<int>>d(n, vector<int>(n, INF));
	vector<int>a(m), b(m), c(m);
	rep(i, 0, n)d[i][i] = 0;
	rep(i, 0, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
		d[a[i]][b[i]] = min(d[a[i]][b[i]], c[i]);
		d[b[i]][a[i]] = min(d[b[i]][a[i]], c[i]);
	}
	rep(k, 0, n) {
		rep(i, 0, n) {
			rep(j, 0, n) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = m;
	rep(i, 0, m) {
		bool check = false;
		rep(j, 0, n) {
			if (d[j][a[i]] + c[i] == d[j][b[i]])check = true;
		}
		if (check)ans--;
	}
	cout << ans << endl;
	return 0;
}