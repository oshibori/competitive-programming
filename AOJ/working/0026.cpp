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
void sink(vector<vector<int>> &v, int x, int y, int size) {
	v[x][y]++;
	if (x + 1 < 10)v[x + 1][y]++;
	if (0 <= x - 1)v[x - 1][y]++;
	if (y + 1 < 10)v[x][y + 1]++;
	if (0 <= y - 1)v[x][y - 1]++;

	if (size >= 2) {
		if (x + 1 < 10) {
			if (y + 1 < 10)v[x + 1][y + 1]++;
			if (y - 1 >= 0)v[x + 1][y - 1]++;
		}
		if (x - 1 >= 0) {
			if (y + 1 < 10)v[x - 1][y + 1]++;
			if (y - 1 >= 0)v[x - 1][y - 1]++;
		}
	}

	if (size >= 3) {
		if (x + 2 < 10)v[x + 2][y]++;
		if (x - 2 >= 0)v[x - 2][y]++;
		if (y + 2 < 10)v[x][y + 2]++;
		if (y - 2 >= 0)v[x][y - 2]++;
	}
}
signed main() {
	char c; int x, y, s;
	vector<vector<int>>v(10, vector<int>(10, 0));
	while (cin >> x >> c >> y >> c >> s) {
		sink(v, x, y, s);
	}
	int cnt(0);
	int m(0);
	rep(i, 0, 10) {
		rep(j, 0, 10) {
			m = max(m, v[i][j]);
			if (v[i][j] == 0)cnt++;
		}
	}
	cout << cnt << endl << m << endl;
	return 0;
}