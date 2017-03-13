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
	int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	rep(i, 0, tx - sx) {
		cout << 'R';
	}
	rep(i, 0, ty - sy) {
		cout << 'U';
	}
	rep(i, 0, tx - sx) {
		cout << 'L';
	}
	rep(i, 0, ty - sy) {
		cout << 'D';
	}
	cout << 'D';
	rep(i, 0, tx - sx + 1) {
		cout << 'R';
	}
	rep(i, 0, ty - sy + 1) {
		cout << 'U';
	}
	cout << 'L'<<'U';
	rep(i, 0, tx - sx + 1) {
		cout << 'L';
	}
	rep(i, 0, ty - sy + 1) {
		cout << 'D';
	}
	cout << 'R' << endl;
	return 0;
}