#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
using ll = long long;
signed main() {
	int n;
	while (cin >> n, n) {
		vector<int>v(n + 1, 0); rep(i, 1, n + 1)cin >> v[i];
		sort(all(v));
		dumpc(v);
		rep(i, 1, n + 1)v[i] += v[i - 1];
		int sum(0);
		rep(i, 1, n) {
			sum += v[i];
		}
		cout << sum << endl;
		dumpc(v);
	}
	return 0;
}