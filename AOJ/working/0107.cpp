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
	int a, b, c;
	while (cin >> a >> b >> c, a || b || c) {
		int n; cin >> n;
		vector<double>R(n);
		rep(i, 0, n)cin >> R[i];
		int m = max(a, max(b, c));
		double x, y;
		if (m == a) {
			x = b; y = c;
		}
		else if (m == b) {
			x = a; y = c;
		}
		else {
			x = a; y = b;
		}

		double z = sqrt(x*x + y*y) / 2.0;

		rep(i, 0, n) {
			if (z < R[i])cout << "OK" << endl;
			else cout << "NA" << endl;
		}

	}
	return 0;
}