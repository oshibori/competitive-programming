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
	int n, k; cin >> n >> k;
	vector<bool>bunny(n + 1, false);
	vector<int>boat(n+1,-1);
	rep(i, 0, k) {
		int m; cin >> m;
		rep(j, 0, m) {
			int b; cin >> b;
			boat[b] = i;
		}
	}

	int r; cin >> r;
	vector<vector<bool>>hate(n + 1, vector<bool>(n + 1, false));
	rep(i, 0, r) {
		int q, p; cin >> p >> q;
		hate[p][q] = true;
		hate[q][p] = true;
	}
	rep(i, 1, n + 1) {
		rep(j, i + 1, n + 1) {
			if (boat[i] == boat[j] && hate[i][j]) {
				bunny[i] = bunny[j] = true;
			}
		}
	}
	cout << accumulate(all(bunny), 0) << endl;
	return 0;
}