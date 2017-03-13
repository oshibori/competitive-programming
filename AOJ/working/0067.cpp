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
vector<string>v(12);
int dfs_visit(int x, int y) {
	if (x < 0 || 12 <= x || y < 0 || 12 <= y)return false;
	
	if (v[x][y] == '1') {
		v[x][y] = '0';
		dfs_visit(x - 1, y);
		dfs_visit(x + 1, y);
		dfs_visit(x, y - 1);
		dfs_visit(x, y + 1);
		return 1;
	}
	else return 0;
}

signed main() {
	while (cin >> v[0]) {
		rep(i, 1, 12)cin >> v[i];
		int cnt(0);
		rep(i, 0, 12)rep(j, 0, 12) {
			cnt += dfs_visit(i, j);
		}
		cout << cnt << endl;
	}
	return 0;
}