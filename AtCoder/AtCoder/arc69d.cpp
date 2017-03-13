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
	int n; cin >> n; string s; cin >> s;

	vector<string>ans(4);

	if (s[0] == 'o') {
		ans[0] = "SSS";
		ans[1] = "WSW";
		ans[2] = "SWW";
		ans[3] = "WWS";
	}
	else {
		ans[0] = "SSW";
		ans[1] = "WSS";
		ans[2] = "SWS";
		ans[3] = "WWW";
	}
	s = (s[s.size() - 1] + s + s[0]);

	rep(i, 0, 4) {
		rep(j, 2, s.size() - 1) {
			if (s[j] == 'o') {
				if (ans[i][j] == 'S') {
					if (ans[i][j - 1] == 'S')ans[i].push_back('S');
					else ans[i].push_back('W');
				}
				else {
					if (ans[i][j - 1] == 'S')ans[i].push_back('W');
					else ans[i].push_back('S');
				}
			}
			else {
				if (ans[i][j] == 'S') {
					if (ans[i][j - 1] == 'S')ans[i].push_back('W');
					else ans[i].push_back('S');
				}
				else {
					if (ans[i][j - 1] == 'S')ans[i].push_back('S');
					else ans[i].push_back('W');
				}
			}
		}
	}

	//rep(i, 0, 4)dump(ans[i]);

	rep(i, 0, 4) {
		if (ans[i][1] == ans[i][s.size() - 1] && ans[i][0] == ans[i][s.size() - 1 - 1]) {
			cout << ans[i].substr(1, n) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}