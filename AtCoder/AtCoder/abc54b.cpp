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
	int n, m; cin >> n >> m;
	vector<string>a(n), b(m);
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, m)cin >> b[i];
	rep(i, 0, n - m + 1) {
		rep(j, 0, n - m + 1) {
			int cnt(0);
			rep(k, 0, m) {
				rep(l, 0, m) {
					if (a[i + k][j + l] == b[k][l])cnt++;
					else goto here;
				}
			}
			here:
			if (cnt == m*m) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}