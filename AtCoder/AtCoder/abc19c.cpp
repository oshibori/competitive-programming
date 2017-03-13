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
int pow2(int x, int y) {
	if (y <= 0)return 1;
	int res = pow2(x*x, y / 2);
	if (1 & y)res *= x;
	return res;
}
signed main() {
	int n; cin >> n; vector<int>v(n); rep(i, 0, n)cin >> v[i];
	sort(v.begin(), v.end());
	map<int, int>mp;
	int a = 0;
	rep(i, 0, n) {
		int t = i + 1;
		if (mp[v[i]] != 0)a++;
		for (int j = 0; v[i] * pow2(2, j) <= 1e9 + 7; j++) {
			mp[v[i] * pow2(2, j)] = t;
		}
	}

	cout << n - a << endl;

	return 0;
}