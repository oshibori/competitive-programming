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
	int n;
	while (cin >> n, n) {
		vector<int>v(n);
		int ans(0);
		bool na_flag(true);
		rep(i, 0, n) {
			cin >> v[i];
			if (v[i] >= 2)na_flag = false;
			if (v[i]) {
				ans++;
				v[i]--;
			}
		}
		if (na_flag)cout << "NA" << endl;
		else cout << ans + 1 << endl;
	}
	return 0;
}