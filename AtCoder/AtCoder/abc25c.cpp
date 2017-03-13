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
	int b[3][3], c[3][3]; memset(b, 0, sizeof(b)); memset(c, 0, sizeof(c));
	rep(i, 0, 2)rep(j, 0, 3)cin >> b[i][j];
	rep(i, 0, 3)rep(j, 0, 2)cin >> c[i][j];

	int a[3][3]; memset(a, 0, sizeof(a));
	a[1][1] = 1;

	rep(i, 0, 8) {

		int p = i & 1 ? 1 : -1;
		vector<vector<int>>v;
		rep(j, 0, 1)rep(k, 0, 2) {
			if ((a[j][k] == p&&a[j + 1][k] == 0) || (a[j][k] == 0 && a[j + 1][k] == p))

		}

	}
	return 0;
}