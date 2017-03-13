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
	rep(i, 0, 3) {
		int h, m, s; cin >> h >> m >> s;
		int in = s + 60 * m + h * 3600;
		cin >> h >> m >> s;
		int out = s + 60 * m + h * 3600;
		int ans = abs(in - out);
		h = ans / 3600;
		ans %= 3600;
		m = ans / 60;
		ans %= 60;
		cout << h << " " << m << " " << ans << endl;
	}
	return 0;
}