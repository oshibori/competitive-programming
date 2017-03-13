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
	int h, w; cin >> h >> w;
	rep(i, 0, h) {
		string s; cin >> s;
		rep(j, 0, w) {
			if (j)cout << " ";
			for (int k = j; k >= 0; k--) {
				if (s[k] == 'c') {
					cout << j - k;
					goto here;
				}
			}
			cout << -1;
		here:;
		}
		cout << endl;
	}

	return 0;
}