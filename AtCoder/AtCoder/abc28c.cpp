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
	vector<int>v(5);
	set<int>S;
	rep(i, 0, 5)cin >> v[i];
	rep(i, 0, 5)rep(j, 0, 5)rep(k, 0, 5) {
		if (i == j || j == k || k == i)continue;
		S.insert(v[i] + v[j] + v[k]);
	}
	int x = *(prev(S.end(), 3));
	cout << x << endl;
	return 0;
}