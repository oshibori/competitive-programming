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
	int W, H; cin >> W >> H; int N = 150;
	vector<vector<int>>v(N, vector<int>(N, 0));
	
	rep(i, 2, H + 2) {
		rep(j, 2, W + 2) {
			int a; cin >> a;
			v[j][i] = a;
		}
	}
	rep(i, 2, H + 2) {
		rep(j, 2, W + 2) {
			if (v[j][i] == 0) {
				int a = 0;
				if (i & 1) {
					a += v[j + 1][i - 1];
					a += v[j + 1][i];
					a += v[j + 1][i + 1];
					a += v[j][i - 1];
					a += v[j - 1][i];
					a += v[j][i + 1];
				}
				else {
					a += v[j - 1][i - 1];
					a += v[j - 1][i];
					a += v[j - 1][i + 1];
					a += v[j][i - 1];
					a += v[j + 1][i];
					a += v[j][i + 1];
				}
				//cout << "j " << j << " i " << i << " a " << a << endl;
				if (a == 6)v[j][i] = 1;
			}
			//cout << v[i][j] << (j == W ? '\n' : ' ');
		}
	}

	int ans(0);
	rep(i, 1, H +10) {
		rep(j, 1, W + 10) {
			if (v[j][i]) {
				int a = 0;
				if (i & 1) {
					a += v[j + 1][i - 1];
					a += v[j + 1][i];
					a += v[j + 1][i + 1];
					a += v[j][i - 1];
					a += v[j - 1][i];
					a += v[j][i + 1];
				}
				else {
					a += v[j - 1][i - 1];
					a += v[j - 1][i];
					a += v[j - 1][i + 1];
					a += v[j][i - 1];
					a += v[j + 1][i];
					a += v[j][i + 1];
				}
				dump(a)
				ans += 6-a;
			}
		}
	}
	cout << ans << endl;
	return 0;
}