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
	int n;
	while (cin >> n, n) {
		map<int, int>mp;
		map<int, bool>check;
		vector<int>id(n);
		bool f(false);
		rep(i, 0, n) {
			int p, q; cin >> id[i] >> p >> q;
			mp[id[i]] += p*q;
			check[id[i]] = false;
		}
		rep(i, 0, n) {
			if (check[id[i]] == false) {
				check[id[i]] = true;
				if (mp[id[i]] >= 1000000) {
					cout << id[i] << endl;
					f = true;
				}
			}
		}
		if (f == false)cout << "NA" << endl;
	}
	return 0;
}