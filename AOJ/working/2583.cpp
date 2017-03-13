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
		vector<string>v(n);
		rep(i, 0, n) {
			cin >> v[i];
			int cnt(0);
			rep(j, 0, v[i].size()) {
				if (v[i][j] == '.') {
					v[i][j] = ' ';
					cnt++;
				}
			}
			if (cnt&&i) {
				v[i][cnt - 1] = '+';
				for (int j = i-1; j >= 0 && cnt -1 <v[j].length(); j--) {
					if (v[j][cnt - 1] == ' ')v[j][cnt - 1] = '|';
					else break;
				}
			}
		}
		rep(i, 0, n)cout << v[i] << endl;
	}
	return 0;
}