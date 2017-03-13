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
	double xa1;
	while (cin >> xa1) {
		double ya1, xa2, ya2, xb1, yb1, xb2, yb2;
		cin >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2;

		if (xb2 < xa1 || yb2 < ya1 || xa2 < xb1 || ya2 < yb1) {
			cout << "NO" << endl;
		}
		else cout << "YES" << endl;
	}
	return 0;
}