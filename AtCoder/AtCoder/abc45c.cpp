#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 0
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
	int space = s.size() - 1;
	int ans(0);
	for (int bits = 0; bits < (1 << space); bits++) {
		string buf(s.substr(0,1));
		dump(bits);
		for (int i = 0; i < space; i++) {
			if (bits&(1 << i)) {
				ans += stoi(buf);
				buf = ""; buf += s[i + 1];
				dump(ans);
			}
			else buf += s[i + 1];
			dump(buf);
		}
		if (buf != "")ans += stoll(buf);
		dump(ans);
	}

	cout << ans << endl;
	return 0;
}