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
		vector<vector<int> >v(n, vector<int>(n, INF));
		rep(i, 0, n)v[i][i] = 0;
		int k; cin >> k;
		bool f = false;
		rep(i, 0, k) {
			int x; cin >> x;
			if (x == 0) {
				if (!f) {
					rep(j, 0, n) {
						rep(l, 0, n) {
							rep(h, 0, n) {
								v[l][h] = min(v[l][h], v[l][j] + v[j][h]);
							}
						}
					}
					f = true;
				}

				int a, b; cin >> a >> b; a--; b--;
				cout << ((v[a][b] == INF) ? -1 : v[a][b]) << endl;
			}
			else {
				int c, d, e; cin >> c >> d >> e; c--; d--;
				v[c][d] = v[d][c] = min(v[c][d], e);
				f = false;
			}
		}
	}
	return 0;
}