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
		vector<int>M(n + 1), D(m + 1);
		rep(i, 1, n + 1)cin >> M[i];
		rep(i, 1, m + 1)cin >> D[i];
		int ans(1), i(1);
		while (i < n) {
			i += D[ans];
			if (i >= n) {
				ans++;
				break;
			}
			i += M[i];
			ans++;
		}
		cout << ans - 1 << endl;
	}
	return 0;
}