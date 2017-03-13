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
	int n, m;
	while (cin >> n >> m, n || m) {
		vector<vector<pair<int, int>>>d(m, vector<pair<int, int>>(m, pair<int, int>(INF, INF)));
		rep(i, 0, m)d[i][i] = make_pair(0, 0);
		int a, b, c, t;
		rep(i, 0, n) {
			cin >> a >> b >> c >> t; a--; b--;
			d[a][b] = d[b][a] = make_pair(c, t);
		}
		rep(k, 0, m) {
			rep(i, 0, m) {
				rep(j, 0, m) {
					d[i][j].first = min(d[i][j].first, d[i][k].first + d[k][j].first);
					d[i][j].second = min(d[i][j].second, d[i][k].second + d[k][j].second);
				}
			}
		}
		int k; cin >> k;
		int p, q, r;
		rep(i, 0, k) {
			cin >> p >> q >> r; p--; q--;
			if (r)cout << d[p][q].second << endl;
			else cout << d[p][q].first << endl;
		}
	}
	return 0;
}