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
	int n; cin >> n;
	while (n--) {
		double x1, y1, x2, y2, r1, r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dis = pow(abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2),0.5);
		if (r1 + r2 < dis)cout << 0 << endl;
		else if (abs(r1 - r2) <= dis&&dis <= abs(r1 + r2))cout << 1 << endl;
		else {
			if (dis < r1 - r2)cout << 2 << endl;
			else cout << -2 << endl;
		}
	}
	return 0;
}