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
	int n, m, s, g1, g2;
	while (cin >> n >> m >> s >> g1 >> g2, n || m || s || g1 || g2) {
		g1--; g2--; s--;
		vector<vector<int> >d(n, vector<int>(n, 1000000));
		rep(i, 0, n)d[i][i] = 0;
		rep(i, 0, m) {
			int b1, b2, c; cin >> b1 >> b2 >> c; b1--; b2--;
			d[b1][b2] = c;
		}
		rep(k, 0, n) {
			rep(i, 0, n) {
				rep(j, 0, n) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		int ans = INF;
		rep(i, 0, n)ans = min(ans, d[s][i] + d[i][g1] + d[i][g2]);
		cout << ans << endl;

	}
	return 0;
}