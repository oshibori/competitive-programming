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
string rev(string s) {
	string res = s;
	reverse(res.begin(), res.end());
	return res;
}
signed main() {
	string s; cin >> s; int n, r, l; cin >> n;
	rep(i, 0, n) {
		cin >> l >> r;
		s = s.substr(0, l - 1) + rev(s.substr(l - 1, r - l + 1)) + s.substr(r);
	}
	cout << s << endl;
	return 0;
}