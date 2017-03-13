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
	char c; vector<int>v(5);
	while (cin >> v[0] >> c >> v[1] >> c >> v[2] >> c >> v[3] >> c >> v[4]) {
		vector<int>trump(15, 0); int m(0); int p = 1;
		rep(i, 0, 5) {
			trump[v[i]]++;
			if (v[i] == 1)trump[14]++;
			m = max(m, trump[v[i]]);
		}
		if (m == 4)p = max(p, 7);
		if (m == 3) {
			rep(i, 1, 14) {
				if (trump[i] == 2) {
					p = max(p, 6);
					break;
				}
			}
			p = max(p, 4);
		}
		rep(i, 1, 11) {
			bool f(true);
			rep(j, i, i + 5) {
				if (trump[j] != 1)f = false;
			}
			if (f)p = max(p, 5);
		}
		if (m == 2) {
			int cnt(0);
			rep(i, 1, 14) {
				if (trump[i] == 2) {
					cnt++;
				}
			}
			if (cnt == 2)p = max(p, 3);
			else p = max(p, 2);
		}

		switch (p) {
		case 1:cout << "null" << endl; break;
		case 2:cout << "one pair" << endl; break;
		case 3:cout << "two pair" << endl; break;
		case 4:cout << "three card" << endl; break;
		case 5:cout << "straight" << endl; break;
		case 6:cout << "full house" << endl; break;
		case 7:cout << "four card" << endl; break;
		}

	}
	return 0;
}