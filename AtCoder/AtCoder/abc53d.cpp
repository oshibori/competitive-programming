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
	int n; cin >> n; vector<int>v(100010, 0); map<int, int>mp;
	rep(i, 0, n) {
		int a; cin >> a;
		mp[a]++;
	}
	int even = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second % 2 == 0)even++;
	}
	cout << mp.size() - (even % 2) << endl;
	return 0;
}