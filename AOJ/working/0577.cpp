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
	int n; cin >> n;
	vector<vector<int>>v(n, vector<int>(3));
	rep(i, 0, n)rep(j, 0, 3)cin >> v[i][j];
	vector<int>ans(n, 0);
	rep(i, 0, 3) {
		vector<int>t(150, 0);
		rep(j, 0, n) {
			t[v[j][i]]++;
		}
		rep(j, 0, n) {
			if (t[v[j][i]] == 1)ans[j] += v[j][i];
		}

	}
	rep(i, 0, n) {
		cout << ans[i] << endl;
	}
	return 0;
}