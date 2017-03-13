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
	vector<int>h(5);
	while (cin >> h[0], h[0]) {
		vector<int>aiko(4, 0);
		aiko[h[0]]++;
		rep(i, 1, 5) {
			cin >> h[i]; aiko[h[i]]++;
		}
		if (aiko[1] && aiko[2] && aiko[3]||aiko[1]==5||aiko[2]==5||aiko[3]==5)rep(i,0,5)cout << 3 << endl;
		else {
			int win, lose;
			if (aiko[1] == 0) { win = 2; lose = 3; }
			else if (aiko[2] == 0) { win = 3; lose = 1; }
			else win = 1; lose = 2;
			rep(i, 0, 5) {
				if (h[i] == win)cout << 1 << endl;
				else cout << 2 << endl;
			}


		}

	}
	return 0;
}