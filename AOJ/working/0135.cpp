#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 0
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
		string s; cin >> s;
		double sh = stoi(s.substr(3, 2)) / 60.0 * 360;
		double lo = stoi(s.substr(0, 2)) * 5 / 60.0 * 360 + sh / 360.0 * 30;
		double dif = min(fabs(lo - sh), 360.0 - fabs(lo - sh));
		dump(lo); dump(sh); dump(dif);
		if (dif < 30.0)cout << "alert" << endl;
		else if (dif < 90)cout << "warning" << endl;
		else cout << "safe" << endl;
	}
	return 0;
}