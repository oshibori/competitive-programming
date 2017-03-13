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
	int n; cin >> n; vector<int>v(n); rep(i, 0, n)cin >> v[i];
	vector<int>A, T;

	rep(i, 0, n) {
		int a(-INF), t(-INF);
		rep(j, 0, n) {
			if (i == j)continue;
			int x(min(i, j)), y(max(i, j));
			int ta(0), tt(0);
			for (int k = 0; x + k <= y; k++) {
				if (k & 1)ta += v[x + k];
				else tt += v[x + k];
			}

			if (a < ta)a = ta, t = tt;

		}
		A.push_back(a), T.push_back(t);
	}
	auto z = max_element(all(T));
	cout << *z << endl;
	return 0;
}