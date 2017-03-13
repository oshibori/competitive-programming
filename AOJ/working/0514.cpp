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
	int a, b, c;
	while (cin >> a >> b >> c, a || b || c) {
		int n; cin >> n;
		vector<int>i, j, k, ans(a + b + c + 1, 2);
		rep(x, 0, n) {
			int e, f, g, h;
			cin >> e >> f >> g >> h;
			if (h) {
				ans[e] = ans[f] = ans[g] = 1;
			}
			else {
				i.push_back(e);
				j.push_back(f);
				k.push_back(g);
			}
		}
		int m = i.size();
		for (int x = 0; x < m; x++) {
			int p(i[x]), q(j[x]), r(k[x]);
			if (ans[p] == 1 && ans[q] == 1 && ans[r] == 2) {
				ans[r] = 0;
			}
			else if (ans[p] == 1 && ans[q] == 2 && ans[r] == 1) {
				ans[q] = 0;
			}
			else if (ans[p] == 2 && ans[q] == 1 && ans[r] == 1) {
				ans[p] = 0;
			}

		}

		rep(x, 1, ans.size())cout << ans[x] << endl;

	}
	return 0;
}