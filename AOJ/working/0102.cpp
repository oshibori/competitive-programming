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
	int n;
	while (cin >> n, n) {
		vector<vector<int>>v(n + 1, vector<int>(n + 1));
		rep(i, 0, n)rep(j, 0, n)cin >> v[i][j];
		rep(i, 0, n) {
			v[i][n] = accumulate(v[i].begin(), v[i].end(), 0);
		}
		rep(i, 0, n + 1) {
			int sum(0);
			rep(j, 0, n)sum += v[j][i];
			v[n][i] = sum;
		}

		rep(i, 0, n + 1) {
			rep(j, 0, n + 1) {
				printf("%5d", v[i][j]);
			}
			cout << endl;
		}
	}
	return 0;
}