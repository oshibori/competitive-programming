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
	string s;
	getline(cin, s);
	string buf; bool f = true;
	rep(i, 0, s.size()) {
		if (s[i] == ' ' || s[i] == '.' || s[i] == ',') {
			if (3 <= buf.size() && buf.size() <= 6) {
				if (f)f = false;
				else cout << " ";
				cout << buf;
				buf = "";
			}
			else buf = "";
		}
		else buf += s[i];
	}
	if (3 <= buf.size() && buf.size() <= 6)cout << " " << buf;
	cout << endl;
	return 0;
}