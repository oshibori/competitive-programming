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
	double m; cin >> m; double vv = 0;
	if (m < 100)vv = 0;
	else if (m <= 5000)vv = m / 100;
	else if (m <= 30000)vv = m / 1000 + 50;
	else if (m <= 70000)vv = (m / 1000 - 30) / 5 + 80;
	else vv = 89;

	int ans = vv;
	if (ans / 10 == 0)cout << 0;
	cout << ans << endl;



	return 0;
}