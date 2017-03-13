#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
bool check(string s) {
	if (s == "dream" || s == "dreamer" || s == "erase" || s == "eraser")return true;
	else false;
}
signed main() {
	string s; cin >> s;
	vector<int>v(s.size(), 0);
	rep(i, 0, s.size()) {
		dump(i);
		if (s.substr(i, 5) == "dream" || s.substr(i, 5) == "erase") {
			rep(j, i, 5 + i) v[j] = 1;
		}
		if (s.substr(i, 6) == "eraser") {
			rep(j, i, 6 + i) v[j] = 1;
		}
		if (s.substr(i, 7) == "dreamer") {
			rep(j, i, 7 + i)v[j] = 1;
		}
	}
	if (accumulate(all(v), 0) == s.size())cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}