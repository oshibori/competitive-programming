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
	string s; cin >> s;
	string ans;
	bool f(false);
	rep(i, 0, s.size()) {
		if (f == false) {
			if (s[i] == 'A') {
				ans.push_back(s[i]);
				f = true;
			}
		}
		else {
			if (s[i] == 'Z') {
				ans.push_back(s[i]);
				f = false;
			}
		}
	}
	f = false;
	for (int i = 0; i + 1 < ans.size(); i++) {
		if (ans[i] == 'A'&&ans[i + 1] == 'Z') {
			cout << "AZ";
			f = true;
			i++;
		}
	}
	if (f == false)cout << -1;
	cout << endl;
	return 0;
}